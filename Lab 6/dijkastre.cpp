// Dijkstra algorithm
#include <iostream>
#define M 3
using namespace std;

void dijkastre(int arr[M][M], int st) {

    int visited[M] = {0};
    int dist[M];

    // Initialize distances with large value
    for(int i = 0; i < M; i++) {
        dist[i] = 10000;   // large number
    }

    dist[st] = 0;

    for(int count = 0; count < M - 1; count++) {

        int min = 10000, u = -1;

        // Find minimum distance vertex
        for(int i = 0; i < M; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        // Update distances
        for(int v = 0; v < M; v++) {
            if(!visited[v] && arr[u][v] != 0 &&
               dist[u] + arr[u][v] < dist[v]) {

                dist[v] = dist[u] + arr[u][v];
            }
        }
    }

    cout << "\nSingle Source Shortest Path from vertex " << st << ":\n";
    for(int i = 0; i < M; i++) {
        cout << "Vertex " << i << " = " << dist[i] << endl;
    }
}

int main() {

    int graph[M][M];

    cout << "Enter adjacency matrix (3x3):\n";
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    dijkastre(graph, start);

    return 0;
}                         