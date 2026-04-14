#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long hornersPower(long long x, int n) {
    long long result = 1;

    for (int i = 0; i < n; i++) {
        result = result * x;
    }

    return result;
}

int main() {

    long long x = 2;

    cout << "Horner's Rule Time Analysis for x^n\n";
    cout << "Exponent(n)\tAverage Time (microseconds)\n";

    for (int n = 1000; n <= 20000; n += 1000) {

        long long totalTime = 0;

        for (int i = 0; i < 100; i++) {

            auto start = high_resolution_clock::now();

            hornersPower(x, n);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            totalTime += duration.count();
        }

        double averageTime = totalTime / 100.0;

        cout << n << "\t\t" << averageTime << endl;
    }

    return 0;
}