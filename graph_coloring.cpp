#include <iostream>
using namespace std;

int graph[10][10], color[10];
int V, m;

bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool graphColor(int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColor(v + 1))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of colors (m): ";
    cin >> m;

    cout << "Enter adjacency matrix (row by row):\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    if (graphColor(0)) {
        cout << "Graph Coloring Solution:\n";

        for (int i = 0; i < V; i++) {
            cout << "color[" << i << "] = " << color[i] << endl;
        }

        cout << "\nSolution array: [ ";
        for (int i = 0; i < V; i++) {
            cout << color[i] << " ";
        }
        cout << "]" << endl;
    }
    else {
        cout << "No solution exists with " << m
             << " colors for this graph.\n";
    }

    return 0;
}
