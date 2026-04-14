#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    cout << "InputSize\tTime(us)\n";

    for (int n = 1000; n <= 10000; n += 1000) {

        int *arr = new int[n];

        // Fill array in reverse order (worst case)
        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        auto start = high_resolution_clock::now();

        insertionSort(arr, n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t\t" << duration.count() << endl;

        delete[] arr;
    }

    return 0;
}