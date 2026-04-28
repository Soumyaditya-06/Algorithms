#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v],
                                     dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][0]);
    }

    cout << "Minimum cost of travelling salesman: " << ans << endl;

    return 0;
}