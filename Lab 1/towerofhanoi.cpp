#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long c = 0;

// simple function
void toh(int n, char a, char b, char c1, bool show) {
    if (n == 0)
        return;

    toh(n - 1, a, c1, b, show);

    c++;
    if (show) {
        cout << "Move disk " << n << " from " << a << " to " << c1 << endl;
    }

    toh(n - 1, b, a, c1, show);
}

int main() {

    int r = 50;

    cout << "n\tTime(ns)\tMoves\tExpected\n";

    for (int n = 3; n <= 15; n++) {

        long long t = 0;
        c = 0;

        for (int i = 0; i < r; i++) {

            auto s = high_resolution_clock::now();

            bool p = (n <= 3);
            toh(n, 'A', 'B', 'C', p);

            auto e = high_resolution_clock::now();

            auto d = duration_cast<nanoseconds>(e - s);
            t += d.count();
        }

        double avg = (double)t / r;
        long long exp = (1LL << n) - 1;

        cout << n << "\t" << avg << "\t"
             << c / r << "\t" << exp << endl;
    }

    return 0;
}