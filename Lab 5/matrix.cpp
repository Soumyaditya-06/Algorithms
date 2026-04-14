#include <iostream>
using namespace std;

int main() {
    int A[4][4], B[4][4], C[4][4];

    // Input Matrix A
    cout << "Enter elements of 4x4 Matrix A:\n";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
    }

    // Input Matrix B
    cout << "Enter elements of 4x4 Matrix B:\n";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> B[i][j];
        }
    }

    // Initialize result matrix
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display result
    cout << "\nResultant Matrix:\n";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}