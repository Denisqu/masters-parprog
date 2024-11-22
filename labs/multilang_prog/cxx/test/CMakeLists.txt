enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests test.cpp)
target_link_libraries(runTests singlethreaded_nonvectorized ${GTEST_LIBRARIES} pthread)