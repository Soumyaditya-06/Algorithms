#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Function to calculate x^n (simple method)
long long power(long long x, int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

// Linear Search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {

    // Example power calculation
    long long x = 2;
    int n_power = 10;
    cout << "Power " << x << "^" << n_power << " = " 
         << power(x, n_power) << endl;

    cout << "\nLinear Search Time Analysis\n";
    cout << "InputSize\tAverage Time (microseconds)\n";

    // Loop from 1000 to 20000
    for (int size = 1000; size <= 20000; size += 1000) {

        long long totalTime = 0;

        for (int count = 0; count < 100; count++) {

            int* arr = new int[size];

            // Fill array with random numbers
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 100000;
            }

            int key = -1;  // worst case (not present)

            auto start = high_resolution_clock::now();

            linearSearch(arr, size, key);

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