#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void swapChar(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(string str, int l, int r) {
    if (l == r) {
        return;
    }

    for (int i = l; i <= r; i++) {
        swapChar(str[l], str[i]);
        permute(str, l + 1, r);
        swapChar(str[l], str[i]); 
    }
}

int main() {

    cout << "Permutation Time Analysis\n";
    cout << "Length(n)\tAverage Time (microseconds)\n";

    for (int n = 1; n <= 10; n++) {

        string str = "";
        
        for (int i = 0; i < n; i++) {
            str += char('A' + i);
        }

        long long totalTime = 0;

        for (int i = 0; i < 100; i++) {

            auto start = high_resolution_clock::now();

            permute(str, 0, str.length() - 1);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            totalTime += duration.count();
        }

        double avgTime = totalTime / 100.0;

        cout << n << "\t\t" << avgTime << endl;
    }

    return 0;
}