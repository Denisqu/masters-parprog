#include <singlethreaded_vectorized_optimized.hpp>
#include <cmath>
#include <numbers>
#include <immintrin.h>
#include <vectorclass.h>
#include <tuple>

#include <cstring>

namespace {

double * pReal(std::complex<double>& value)
{
    return &reinterpret_cast<double *>( &value )[0];
}

double * pImage(std::complex<double>& value)
{
    return &reinterpret_cast<double *>( &value )[1];
}

}

namespace SingleThreaded_Vectorized_Optimized {

ComplexVector FFTConverter::convert(const ComplexVector& inputVector)
{
    ComplexVector result(inputVector);
    convertMutable(result);
    return result;
}

void FFTConverter::convertMutable(ComplexVector& inputVector)
{
    int n = inputVector.size();
    if (__builtin_expect(n <= 1, 0)) {
        return;
    }

    ComplexVector a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        a0[i] = inputVector[2*i];
        a1[i] = inputVector[2*i+1];
    }
    convertMutable(a0);
    convertMutable(a1);

    double ang = 2 * std::numbers::pi / n;
    Vec2d w_vec  { 1, 0 },
          wn_vec { cos(ang), sin(ang) };
    for (int i = 0; 2 * i < n; i += 4)  {
        Vec2d value = [&]() -> Vec2d {
            auto vec = Vec2d();
            vec.load(pReal(a1[i]));
            vec *= w_vec;
            return vec;
        }();
        {
            auto vec = Vec2d();
            vec.load(pReal(a0[i]));
            vec += value;
            vec.store(pReal(inputVector[i]));
        }
        {
            auto vec = Vec2d();
            vec.load(pReal(a0[i]));
            vec -= value;
            vec.store(pReal(inputVector[i + n/2]));
        }
        w_vec *= wn_vec;
    }
}

} // namespace SingleThreaded_Vectorized_Optimized


/* * * * * * * * * * * * * * * * * * * * * *
 *
 *      Работает медленнее:
        __m128d o = _mm_load_pd( (double *)&inputVector[i + n/2 ] );   // odd
        double cc = cos(-2.*std::numbers::pi*i / n);
        double ss = sin(-2.*std::numbers::pi*i / n);
        __m128d wr = _mm_load1_pd(&cc);			//__m128d wr =  _mm_set_pd( cc,cc );		// cc
        __m128d wi = _mm_set_pd(ss, -ss);		// -d | d	, note that it is reverse order
        // compute the w*o
        wr = _mm_mul_pd(o, wr);					// ac|bc
        __m128d n1 = _mm_shuffle_pd(o, o, _MM_SHUFFLE2(0, 1)); // invert
        wi = _mm_mul_pd(n1, wi);				// -bd|ad
        n1 = _mm_add_pd(wr, wi);				// ac-bd|bc+ad
        o = _mm_load_pd((double *)&inputVector[i]);		// load even part
        wr = _mm_add_pd(o, n1);					// compute even part, inputVector_e + w * inputVector_o;
        wi = _mm_sub_pd(o, n1);					// compute odd part,  inputVector_e - w * inputVector_o;
        _mm_store_pd((double *)&inputVector[i],wr);
        _mm_store_pd((double *)&inputVector[i + n/2],wi);
*/
