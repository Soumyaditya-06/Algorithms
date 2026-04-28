#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1;
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    // Start time
    auto start = high_resolution_clock::now();

    int result = linearSearch(arr, n, key);

    // End time
    auto stop = high_resolution_clock::now();

    // Time duration
    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}