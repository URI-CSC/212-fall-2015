cmake_minimum_required(VERSION 3.10)
project(csc212-lab-07)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_mergesort mergesort.cpp test_mergesort.cpp)
add_executable(test_quicksort quicksort.cpp test_quicksort.cpp)
add_executable(test_customsort customsort.cpp test_customsort.cpp)
add_executable(bench_customsort customsort.cpp mergesort.cpp quicksort.cpp bench_customsort.cpp)
add_executable(test_quicksort_median_pivot quicksort_median_pivot.cpp test_quicksort_median_pivot.cpp)