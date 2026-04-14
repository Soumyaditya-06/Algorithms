#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Function to calculate x^n
long long power(int x, int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {

    // Example: calculate x^n
    int x = 2, n = 10;
    cout << "Power " << x << "^" << n << " = " << power(x, n) << endl;

    cout << "\nBubble Sort Time Analysis\n";
    cout << "InputSize\tAverage Time (microseconds)\n";

    // Loop from 1000 to 20000
    for (int size = 1000; size <= 20000; size += 1000) {

        long long totalTime = 0;

        for (int count = 0; count < 100; count++) {

            int* arr = new int[size];

            // Generate random numbers
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }

            auto start = high_resolution_clock::now();

            bubbleSort(arr, size);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            totalTime += duration.count();

            delete[] arr;
        }

        double averageTime = totalTime / 100.0;

        cout << size << "\t\t" << averageTime << endl;
    }

    return 0;
}