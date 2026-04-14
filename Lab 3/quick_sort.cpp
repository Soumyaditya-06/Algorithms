#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    cout << "InputSize\tTime(us)\n";

    for (int n = 1000; n <= 10000; n += 1000) {

        int *arr = new int[n];

        // Fill array with random values
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 10000;

        auto start = high_resolution_clock::now();

        quickSort(arr, 0, n - 1);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t\t" << duration.count() << endl;

        delete[] arr;
    }

    return 0;
}