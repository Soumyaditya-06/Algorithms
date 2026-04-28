#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();

    vector<vector<int>> C(n, vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;

    // Divide matrices
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k));
    vector<vector<int>> A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k));
    vector<vector<int>> B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Helper lambdas (short add/sub)
    auto add = [&](vector<vector<int>> X, vector<vector<int>> Y) {
        vector<vector<int>> R(k, vector<int>(k));
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                R[i][j] = X[i][j] + Y[i][j];
        return R;
    };

    auto sub = [&](vector<vector<int>> X, vector<vector<int>> Y) {
        vector<vector<int>> R(k, vector<int>(k));
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                R[i][j] = X[i][j] - Y[i][j];
        return R;
    };

    // Strassen formulas (short)
    auto M1 = strassen(add(A11,A22), add(B11,B22));
    auto M2 = strassen(add(A21,A22), B11);
    auto M3 = strassen(A11, sub(B12,B22));
    auto M4 = strassen(A22, sub(B21,B11));
    auto M5 = strassen(add(A11,A12), B22);
    auto M6 = strassen(sub(A21,A11), add(B11,B12));
    auto M7 = strassen(sub(A12,A22), add(B21,B22));

    // Combine
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j+k] = M3[i][j] + M5[i][j];
            C[i+k][j] = M2[i][j] + M4[i][j];
            C[i+k][j+k] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
        }
    }

    return C;
}

int main() {
    int n;
    cout << "Enter size (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter Matrix A:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> B[i][j];

    vector<vector<int>> C = strassen(A,B);

    cout << "\nResult Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}