#include <bits/stdc++.h>
using namespace std;

// Function to check if it's safe to color a vertex
bool isSafe(int node, vector<vector<int>>& graph, vector<int>& colors, int color) {
    for (int neighbor : graph[node]) {
        if (colors[neighbor] == color) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Backtracking function to solve the graph coloring problem
bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& colors, int m, int node) {
    int n = graph.size();
    if (node == n) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, graph, colors, c)) {
            colors[node] = c; // Assign color
            if (graphColoringUtil(graph, colors, m, node + 1)) {
                return true;
            }
            colors[node] = 0; // Backtrack
        }
    }

    return false;
}

// Function to solve the graph coloring problem
bool graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0); // 0 means no color assigned yet

    if (graphColoringUtil(graph, colors, m, 0)) {
        cout << "Solution Exists: Following are the assigned colors:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " -> Color " << colors[i] << endl;
        }
        return true;
    } else {
        cout << "No solution exists with " << m << " colors." << endl;
        return false;
    }
}

int main() {
    int n, e, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    cout << "Enter the number of colors: ";
    cin >> m;

    graphColoring(graph, m);

    return 0;
}
