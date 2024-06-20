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

// Function to perform Selection Sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

int main() {
    // Generate a vector of 500,000 random numbers
    std::vector<int> arr_selection = generateRandomVector(10000);

    // Record the start time
    auto startTimeSelection = std::chrono::high_resolution_clock::now();

    // Apply Selection Sort on the generated vector
    selectionSort(arr_selection);

    // Record the end time
    auto endTimeSelection = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto durationSelection = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeSelection - startTimeSelection);

    // Display the execution time
    std::cout << "Execution time of Selection Sort for 500,000 elements: " << durationSelection.count() << " milliseconds\n";

    return 0;
}
