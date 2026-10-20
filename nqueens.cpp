#include <iostream>
#include <cstdlib>
using namespace std;

int N, solutionCount = 0;
int position[20];

bool Promising(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (position[i] == col ||
            abs(row - i) == abs(col - position[i])) {
            return false;
        }
    }
    return true;
}

void printSolution() {
    solutionCount++;

    cout << "Solution " << solutionCount << ": [ ";

    for (int i = 0; i < N; i++)
        cout << position[i] << " ";

    cout << "]" << endl;
}

void NQueens(int row) {
    if (row == N) {
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (Promising(row, col)) {
            position[row] = col;

            NQueens(row + 1);

            position[row] = -1;  // Backtracking
        }
    }
}

int main() {
    cout << "Enter the value of N: ";
    cin >> N;

    if (N < 1 || N > 20) {
        cout << "Enter N between 1 and 20.";
        return 0;
    }

    NQueens(0);

    cout << "Total solutions for N = " << N
         << " : " << solutionCount << endl;

    return 0;
}
