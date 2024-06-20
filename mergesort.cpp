#include <iostream>
#include <vector>
#include <chrono>

// Function to merge two sorted subvectors into one sorted vector
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary vectors
    std::vector<int> L(n1), R(n2);

    // Copy data to temporary vectors L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary vectors back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Function to implement Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    // Generate a vector of 10,000 random numbers
    std::vector<int> arr(100000000);
    for (int i = 0; i < 100000000; ++i)
        arr[i] = rand() % 100000000;

    // Record the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    // Apply Merge Sort on the generated vector
    mergeSort(arr, 0, arr.size() - 1);

    // Record the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Display the execution time
    std::cout << "Execution time of Merge Sort for 10,000 elements: " << duration.count() << " milliseconds\n";

    return 0;
}
