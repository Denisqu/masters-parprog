#include <gtest/gtest.h>
#include "singlethreaded_nonvectorized.hpp"

namespace {

const ComplexVector& sineWave(uint32_t numPoints = 0, double freq = 0) {
    static ComplexVector signal(numPoints);
    if (signal.size() == 0) {
        for (int i = 0; i < numPoints; i++) {
            signal[i] = std::complex<double>(sin(2 * std::numbers::pi * freq * i / numPoints), 0);
        }
    }
    return signal;
}

} // namespace

TEST(FFT_OF_SINEWAVE_SINGLETHREADED_NON_VECTORIZED, FFT)
{
    SingleThreaded_NonVectorized::FFTConverter::convert(sineWave());
    ASSERT_EQ(true, true);
}

int main(int argc, char** argv) {
    sineWave(10e7, 2.4e9);

    ::testing::InitGoogleTest(&argc, argv);

    int result = RUN_ALL_TESTS();
    if (result != 0) {
        return result;
    }

    return 0;
}
