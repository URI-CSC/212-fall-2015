#include "quicksort.h"

size_t partition(std::vector<int> &v, size_t left, size_t right) {
    // TODO: Partition `v[left:right]` into `v[left:pivot]` and `v[pivot:right]` such that all elements in
    // `v[left:pivot]` are less than `v[pivot]` and all elements in `v[pivot:right]` are greater than or equal to
    // `v[pivot]`. Return `pivot`.
}

void quicksort_rec(std::vector<int> &v, size_t left, size_t right) {
    // TODO: Sort `v[left:right]` in increasing order. Use `quicksort_rec` and `partition`.
}

void quicksort(std::vector<int> &v) {
    // TODO: Sort `v` in increasing order. Use `quicksort_rec`.
}
