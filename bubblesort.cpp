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

// Function to implement Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place, so we don't need to check them
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Generate a vector of 10,000 random numbers
    std::vector<int> arr = generateRandomVector(100);

    // Record the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    // Apply Bubble Sort on the generated vector
    bubbleSort(arr);

    // Record the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Display the execution time
    std::cout << "Execution time of Bubble Sort for 10,000 elements: " << duration.count() << " milliseconds\n";

    return 0;
}
