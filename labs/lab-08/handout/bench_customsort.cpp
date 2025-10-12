#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <random>



int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    const auto n = std::stoi(argv[1]);
    if (n <= 0) {
        std::cerr << "Error: n must be a positive integer.\n";
        return 1;
    }

    std::vector<int> sorted(n);
    std::vector<int> reverse_sorted(n);
    std::vector<int> random(n);

    for (int i = 0; i < n; ++i) {
        sorted[i] = i;
        reverse_sorted[i] = n - i - 1;
        random[i] = i;
    }

    std::shuffle(random.begin(), random.end(), std::mt19937{std::random_device{}()});

    {
        std::vector<int> arr = sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        quicksort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "quicksort (sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = reverse_sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        quicksort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "quicksort (reverse sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = random;
        const auto start = std::chrono::high_resolution_clock::now();
        quicksort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "quicksort (random): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }

    {
        std::vector<int> arr = sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        mergesort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "mergesort (sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = reverse_sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        mergesort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "mergesort (reverse sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = random;
        const auto start = std::chrono::high_resolution_clock::now();
        mergesort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "mergesort (random): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }

    {
        std::vector<int> arr = sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        customsort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "customsort (sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = reverse_sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        customsort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "customsort (reverse sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = random;
        const auto start = std::chrono::high_resolution_clock::now();
        customsort(arr);
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "customsort (random): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }

    {
        std::vector<int> arr = sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        std::sort(arr.begin(), arr.end());
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "std::sort (sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = reverse_sorted;
        const auto start = std::chrono::high_resolution_clock::now();
        std::sort(arr.begin(), arr.end());
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "std::sort (reverse sorted): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
    {
        std::vector<int> arr = random;
        const auto start = std::chrono::high_resolution_clock::now();
        std::sort(arr.begin(), arr.end());
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "std::sort (random): "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }

    return 0;
}
