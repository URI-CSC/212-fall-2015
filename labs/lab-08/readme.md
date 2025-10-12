# Lab 8 - Recursive Sorting Algorithms

# Overview

In this lab, you will implement and analyze recursive sorting algorithms.

## Learning Objectives

By the end of this lab, you should be able to:

1. Implement mergesort and quicksort.
2. Evaluate the performance characteristics and sort properties (i.e. in-place, stable) of mergesort and quicksort.

## Grading

To receive full credit, you should:

1. Attend, participate and collaborate.
2. Make at least one submission to Gradescope.

> [!IMPORTANT]
> Effort is enough to receive full credit. You do not need to successfully complete any activities.

## Milestones

To achieve the lab objectives, you should:

1. Complete all activities listed under **Core Content**.

> [!NOTE]
> If you do not complete all activities listed under **Core Content** during the lab period, we recommend finishing them
> on your own. Subsequent labs, assignments and lectures will assume you have completed this lab's **Core Content**
> activities.

To leave early, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice** or **Optional Advanced Topics**.

To maximize your learning, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice**.
3. Attempt some activities listed under **Optional Advanced Topics**.

# Core Content

## Project Setup

1. Create a new project called `csc212-lab-08` in your IDE.
2. Download all files from [the lab handout folder](handout) into the `csc212-lab-08` project.

> [!NOTE]
> To download all files from the repository, navigate to the root of the repository, click on the green **Code** button
> and select **Download Zip**.`

## Mergesort

### Implementation

In this section, you will implement mergesort.

1. Complete `mergesort.cpp`.
2. Build `test_mergesort` from `mergesort.cpp`, and `test_mergesort.cpp`.
3. Run `test_mergesort`. All tests should pass.

> [!IMPORTANT]
> Submit `mergesort.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your mergesort implementation. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of mergesort. Record your answer under
   **Theoretical Analysis** in `mergesort.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of mergesort? Record your answer under
   **Theoretical Analysis** in `mergesort.md`.
3. Determine if mergesort is (a) in-place and/or (b) stable. Record your answer under **Theoretical Analysis** in
   `mergesort.md`.

<details>
<summary>Solution</summary>

1. Let $T(n)$ be the time required for mergesort to sort an array of size $n$. On an input array of size $n$, mergesort
   splits the array into two pieces, each of size $n/2$, and recursively calls mergesort on each piece. This
   takes $T(n/2)$ time for each piece. Then, mergesort merges the two arrays of size $n/2$ in $\Theta(n)$ time. Thus,
   $T(n) = 2T(n/2) + \Theta(n)$. Also, sorting an array of size $1$ takes constant time, so $T(1) = \Theta(1)$.
2. After one iteration, we have that $T(n) = 2T(n/2) + \Theta(n)$. After two iterations, we have that
   $T(n) = 2^2T(n/2^2) + 2\Theta(n)$. After three iterations, we have that
   $T(n) = 2^3T(n/2^3) + 3\Theta(n)$. After $k$ iterations, we have that $T(n) = 2^kT(n/2^k) + k\Theta(n)$. To get to
   the base-case $T(1)$, we take $n/2^k = 1$ so $k = \lg n$. Plugging in, we find that
   $T(n) = 2^{\lg n}T(n/2^{\lg n}) + \Theta(n) \lg n = nT(1) + \Theta(n \lg n) = \Theta(n \lg n)$
3. Mergesort takes $\Theta(n)$ extra memory so it is not in-place. Mergesort is stable since it never swaps non-adjacent
   elements.

</details>

> [!IMPORTANT]
> Submit `mergesort.md` to Gradescope.

## Quicksort

### Implementation

In this section, you will implement quicksort.

1. Complete `quicksort.cpp`.
2. Build `test_quicksort` from `quicksort.cpp`, and `test_quicksort.cpp`.
3. Run `test_quicksort`. All tests should pass.

> [!IMPORTANT]
> Submit `quicksort.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your quicksort implementation. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of quicksort. Record your answer under
   **Theoretical Analysis** in `quicksort.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of quicksort? Record your answer under
   **Theoretical Analysis** in `quicksort.md`.
3. Determine if quicksort is (a) in-place and/or (b) stable. Record your answer under **Theoretical Analysis** in
   `quicksort.md`.

<details>
<summary>Solution</summary>

1. Let $T(n)$ be the time required for quicksort to sort an array of size $n$. On an input array of size $n$, quicksort
   selects a pivot and partitions the array into two pieces in $\Theta(n)$ time. In the worst-case, one piece has size
   $1$ and the other piece has size $n - 1$. Each piece is recursively sorted with quicksort which takes $T(n-1) + T(1)$
   time. Thus, $T(n) = T(n - 1) + T(1) + \Theta(n)$. Also, sorting an array of size $1$ takes constant time, so
   $T(1) = \Theta(1)$.
2. Since $T(1) = \Theta(1)$, $T(n) = T(n-1) + \Theta(n)$. After one iteration, we have that $T(n) = T(n-1) + \Theta(n)$.
   After two iterations, we have that $T(n) = T(n-2) + 2\Theta(n)$. After three iterations, we have that
   $T(n) = T(n-3) + 3\Theta(n)$. After $k$ iterations, we have that $T(n) = T(n-k) + k\Theta(n)$. To get to the
   base-case $T(1)$, we take $n - k = 1$ so $k = n - 1$. Plugging in, we find that
   $T(n) = T(n - (n - 1)) + (n-1)\Theta(n) = T(1) + \Theta(n^2) = \Theta(n^2)$.
3. Quicksort is not stable since it swaps non-adjacent elements. Whether quicksort is in-place is debatable. In the
   worst-case, it performs $\Theta(n)$ recursive calls which requires $\Theta(n)$ space on the stack. If stack space
   counts, quicksort is not in-place. If stack space does not count, quicksort is in-place.

</details>

> [!IMPORTANT]
> Submit `quicksort.md` to Gradescope.

# Extra Practice

## Custom Sort

Most real-world sort implementations are highly customized in order to improve performance. Sort designers employ many
tricks including

1. Increasing the base-case size, and switching from a recursive sort to an iterative sort.
2. Tuning the partition function in quicksort.
3. Increasing the number of recursive calls in quicksort and mergesort.
4. Switching from quicksort to another sorting function when the recursion gets deep, or switching the partition
   function.

among many others.

### Implementation

In this section, you will design and implement your custom sort.

1. Brainstorm at least five different ideas to improve the performance of mergesort or quicksort.
2. Complete `customsort.cpp`. Implement at least two of your ideas.
3. Build `test_customsort` from `customsort.cpp`, and `test_customsort.cpp`.
4. Run `test_customsort`. All tests should pass.

> [!IMPORTANT]
> Submit `customsort.cpp` to Gradescope.

### Empirical Analysis

In this section, you will analyze the empirical performance of your custom sort.

1. Read `bench_customsort.cpp`.
2. Build `bench_customsort` from `customsort.cpp`, `mergesort.cpp`, `quicksort.cpp` and `bench_customsort.cpp`. This
   program takes one command line argument, `n`, the size of the array to sort, and outputs the runtime of your custom
   sorting algorithm, your mergesort, your quicksort and `std::sort`.
3. Run `bench_customsort`. Experiment with different values of `n`. How well does your custom sort perform compared to
   the other sorting algorithms? Record your experiments under **Empirical Analysis** in `customsort.md`.

> [!IMPORTANT]
> Submit `customsort.md` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your custom sort implementation.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your custom sort. Record your answer under
   **Theoretical Analysis** in `customsort.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of your custom sort? Record your answer
   under **Theoretical Analysis** in `customsort.md`.
3. Determine if your custom sort is (a) in-place and/or (b) stable. Record your answer under **Theoretical Analysis** in
   `customsort.md`.

> [!IMPORTANT]
> Submit `customsort.md` to Gradescope.

# Optional Advanced Topics

## Quicksort with Median Pivot

Quicksort runs in worst-case $\Theta(n^2)$ time because the partition function can choose a bad pivot. However, it's
possible to compute the median of an array of $n$ elements in $\Theta(n)$ time with another recursive algorithm. Using
this median as the pivot yields a worst-case runtime of $\Theta(n \lg n)$.

### Implementation

In this section, you will implement quicksort with a median pivot.

1. Complete `quicksort_median_pivot.cpp`.
2. Build `test_quicksort_median_pivot` from `quicksort_median_pivot.cpp`, and `test_quicksort_median_pivot.cpp`.
3. Run `test_quicksort_median_pivot`. All tests should pass.

> [!IMPORTANT]
> Submit `quicksort_median_pivot.cpp` to Gradescope.
