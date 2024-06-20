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

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    // Generate a vector of 500,000 random numbers
    std::vector<int> arr = generateRandomVector(10000);

    // Record the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    // Apply Insertion Sort on the generated vector
    insertionSort(arr);

    // Record the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Display the execution time
    std::cout << "Execution time of Insertion Sort for 500,000 elements: " << duration.count() << " milliseconds\n";

    return 0;
}
