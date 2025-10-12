#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include "mergesort.h"

TEST_CASE("mergesort - empty array") {
    std::vector<int> arr;
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    mergesort(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("mergesort - single element") {
    std::vector<int> arr = {42};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    mergesort(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("mergesort - small unsorted array") {
    std::vector<int> arr = {3, 1, 2};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    mergesort(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("mergesort - already sorted array") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    mergesort(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("mergesort - reverse sorted array") {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    mergesort(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("mergesort - duplicates") {
    std::vector<int> arr = {4, 2, 2, 4, 1, 3, 1};
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    mergesort(arr);
    CHECK_EQ(arr, expected);
}

TEST_CASE("mergesort - large random array") {
    const int n = 10000;
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 0);
    std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});
    std::vector<int> expected = arr;

    std::sort(expected.begin(), expected.end());
    mergesort(arr);

    CHECK_EQ(arr, expected);
}
