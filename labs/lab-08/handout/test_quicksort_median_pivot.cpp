#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include "quicksort_median_pivot.h"

TEST_CASE("quicksort_median_pivot - empty array") {
    std::vector<int> arr;
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("quicksort_median_pivot - single element") {
    std::vector<int> arr = {42};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("quicksort_median_pivot - small unsorted array") {
    std::vector<int> arr = {3, 1, 2};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("quicksort_median_pivot - already sorted array") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("quicksort_median_pivot - reverse sorted array") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("quicksort_median_pivot - duplicates") {
    std::vector<int> arr = {4, 2, 2, 4, 1, 3, 1};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("quicksort_median_pivot - large random array") {
    const int n = 10000;
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 0);
    std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});
    std::vector<int> expected = arr;

    std::sort(expected.begin(), expected.end());
    quicksort_median_pivot(arr);

    CHECK_EQ(arr, expected);
}
