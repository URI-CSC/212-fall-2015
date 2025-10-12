#include "mergesort.h"

void merge(std::vector<int> &v, size_t left, size_t mid, size_t right, std::vector<int> &aux) {
    // TODO: Assume `v[left:mid]` and `v[mid:right]` are sorted in increasing order. Merge the two sorted subarrays into
    // a single sorted subarray `v[left:right]`. Use `aux` for extra space.
}

void mergesort_rec(std::vector<int> &v, size_t left, size_t right, std::vector<int> &aux) {
    // TODO: Sort `v[left:right]` in increasing order. Use `mergesort_rec` and `merge`.
}

void mergesort(std::vector<int> &v) {
    // TODO: Sort `v` in increasing order. Use `mergesort_rec`.
}
