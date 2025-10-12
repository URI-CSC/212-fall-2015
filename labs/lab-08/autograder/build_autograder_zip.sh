#!/bin/bash

rm -rf ./submission/ ./autograder.zip
mkdir -p ./submission/
cp ../handout/mergesort.h ./submission/
cp ../handout/test_mergesort.cpp ./submission/
cp ../handout/doctest.h ./submission/
cp ../handout/quicksort.h ./submission/
cp ../handout/test_quicksort.cpp ./submission/
cp ../handout/doctest.h ./submission/
cp ../handout/customsort.h ./submission/
cp ../handout/test_customsort.cpp ./submission/
cp ../handout/doctest.h ./submission/
cp ../handout/quicksort_median_pivot.h ./submission/
cp ../handout/test_quicksort_median_pivot.cpp ./submission/
cp ../handout/doctest.h ./submission/
zip -r autograder.zip .
rm -rf ./submission/