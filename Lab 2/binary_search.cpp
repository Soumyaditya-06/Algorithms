 #include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    cout << "InputSize\tTime(us)\n";

    for (int n = 1000; n <= 20000; n += 1000) {

        int *arr = new int[n];

        // Fill sorted array
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        int key = n;  // worst case (last element)

        auto start = high_resolution_clock::now();

        binarySearch(arr, n, key);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t\t" << duration.count() << endl;

        delete[] arr;
    }

    return 0;
}