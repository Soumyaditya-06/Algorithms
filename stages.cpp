#include <iostream>
#include <climits>
using namespace std;

#define MAX 11

void roweight(int arr[][MAX], int v) {
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> arr[i][j];
        }
    }
}
void multistage(int arr[][MAX], int v) {
    int dist[MAX], path[MAX];

    dist[v - 1] = 0; 

    for (int i = v - 2; i >= 0; i--) {
        dist[i] = INT_MAX;

        for (int j = i + 1; j < v; j++) {
            if (arr[i][j] != 0 && arr[i][j] + dist[j] < dist[i]) {
                dist[i] = arr[i][j] + dist[j];
                path[i] = j;
            }
        }
    }

    cout << "\nMinimum cost: " << dist[0] << endl;

    cout << "Path: ";
    int i = 0;
    while (i < v - 1) {
        cout << i << " -> ";
        i = path[i];
    }
    cout << v - 1 << endl;
}

int main() {
    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    int arr[MAX][MAX] = {0};

    roweight(arr, v);
    multistage(arr, v);

    return 0;
}