/*
 * Assignment 7 - Kirti Super Market: All-Pairs Shortest Transit Time
 * Floyd-Warshall Algorithm (Dynamic Programming)
 *
 * Reads:
 *   V              -> number of stores
 *   E              -> number of direct transit routes
 *   E lines of u v w  -> directed edge u->v with weight w (w may be negative)
 *
 * Prints:
 *   V x V shortest-distance matrix (INF where unreachable), OR
 *   "ERROR: Negative Cycle Detected" if a negative-weight cycle exists.
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX / 4;   // large sentinel, safe from overflow when added

int main() {
    int V, E;
    cin >> V >> E;

    // (i) Initialization of the distance matrix
    vector<vector<long long>> d(V, vector<long long>(V, INF));
    for (int i = 0; i < V; i++) d[i][i] = 0;

    for (int e = 0; e < E; e++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // If multiple edges exist between the same pair, keep the smaller weight.
        if (w < d[u][v]) d[u][v] = w;
    }

    // (ii) Triple nested loop with relaxation condition
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (d[i][k] >= INF) continue;          // skip unreachable intermediates
            for (int j = 0; j < V; j++) {
                if (d[k][j] >= INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // (iii) Negative-cycle detection: check the diagonal after all passes
    bool negativeCycle = false;
    for (int i = 0; i < V; i++) {
        if (d[i][i] < 0) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "ERROR: Negative Cycle Detected" << endl;
        return 0;
    }

    // Print the V x V shortest-distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (d[i][j] >= INF) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << d[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}
