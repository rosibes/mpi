#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <chrono>  // for time measurement

// Function to generate a vector of random numbers
std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec(size);
    // Seed the random number generator
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        vec[i] = rand() % size; // Generate a random number between 0 and size-1
    }
    return vec;
}

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; ++j) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Generate a vector of 500,000 random numbers
    std::vector<int> arr_quick = generateRandomVector(100000000);

    // Record the start time
    auto startTimeQuick = std::chrono::high_resolution_clock::now();

    // Apply Quick Sort on the generated vector
    quickSort(arr_quick, 0, arr_quick.size() - 1);

    // Record the end time
    auto endTimeQuick = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto durationQuick = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeQuick - startTimeQuick);

    // Display the execution time
    std::cout << "Execution time of Quick Sort for 500,000 elements: " << durationQuick.count() << " milliseconds\n";

    return 0;
}
