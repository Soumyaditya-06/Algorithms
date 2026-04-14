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

// Selection Sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {

    // Example power calculation
    int x = 2, n = 10;
    cout << "Power " << x << "^" << n << " = " << power(x, n) << endl;

    cout << "\nSelection Sort Time Analysis\n";
    cout << "InputSize\tAverage Time (microseconds)\n";

    // Loop from 1000 to 20000
    for (int size = 1000; size <= 20000; size += 1000) {

        long long totalTime = 0;

        for (int count = 0; count < 100; count++) {

            int* arr = new int[size];

            // Generate random array
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }

            auto start = high_resolution_clock::now();

            selectionSort(arr, size);

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