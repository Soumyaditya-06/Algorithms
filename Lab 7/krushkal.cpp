#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent, rankArr;

// Find with path compression
int findSet(int i) {
    if (parent[i] != i)
        parent[i] = findSet(parent[i]);
    return parent[i];
}

// Union by rank
void unionSet(int u, int v) {
    int rootU = findSet(u);
    int rootV = findSet(v);

    if (rootU != rootV) {
        if (rankArr[rootU] < rankArr[rootV]) {
            parent[rootU] = rootV;
        } else if (rankArr[rootU] > rankArr[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rankArr[rootU]++;
        }
    }
}

// Comparator for sorting edges
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Initialize DSU
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int minCost = 0;
    int edgeCount = 0;

    cout << "\nEdges in MST:\n";

    for (auto edge : edges) {
        if (findSet(edge.u) != findSet(edge.v)) {
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
            minCost += edge.w;
            unionSet(edge.u, edge.v);
            edgeCount++;

            if (edgeCount == n - 1)
                break;
        }
    }

    cout << "Minimum Cost = " << minCost << endl;

    return 0;
}