#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " numbers:\n";

    int xorAll = 0;
    int xorArr = 0;

    for (int i = 1; i <= n; i++)
        xorAll ^= i;

    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
        xorArr ^= arr[i];
    }

    cout << "Missing Number = " << (xorAll ^ xorArr);

    return 0;
}