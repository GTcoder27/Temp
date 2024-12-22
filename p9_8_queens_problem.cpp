#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> paths;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(vector<pair<int, int>>& path, int row, int col) {
    for (auto queen : path) {
        int qRow = queen.first;
        int qCol = queen.second;

        // Check same column and diagonals
        if (qCol == col || abs(qRow - row) == abs(qCol - col)) {
            return false;
        }
    }
    return true;
}

void travel(int n, vector<pair<int, int>> path, int row) {
    if (row > n) {
        paths.push_back(path);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(path, row, col)) {
            path.push_back({row, col});
            travel(n, path, row + 1);
            path.pop_back(); // Backtrack
        }
    }
}

int main() {
    int n = 8; // You can change this to any N
    vector<pair<int, int>> path;
    travel(n, path, 1);  

    // Output all solutions
    cout << "Total solutions: " << paths.size() << endl;
    for (auto path : paths) {
        for (auto p : path) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
