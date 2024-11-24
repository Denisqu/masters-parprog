#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>
#include "cxxlib/lib/multithreaded_vectorized_aligned_optimized/multithreaded_vectorized_aligned_optimized.hpp"

PYBIND11_MODULE(fft_pylib, m) {
    pybind11::class_<Multithreaded_Vectorized_Aligned_Optimized::FFTConverter>(m, "FFTConverter")
        .def_static("convert", &Multithreaded_Vectorized_Aligned_Optimized::FFTConverter::convert, "Convert a complex vector");
}
