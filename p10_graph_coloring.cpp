#include <bits/stdc++.h>
using namespace std;

// Function to color the graph
void color(vector<vector<int>>& nodes) {
    int n = nodes.size();
    vector<char> colors(n, ' '); // ' ' means no color assigned yet
    vector<char> availableColors = {'R', 'G', 'B'}; // Available colors

    // Assign colors to each vertex
    for (int i = 0; i < n; i++) {
        set<char> usedColors;

        // Check colors of adjacent vertices
        for (int neighbor : nodes[i]) {
            if (colors[neighbor] != ' ') {
                usedColors.insert(colors[neighbor]);
            }
        }

        // Find the first color not used by neighbors
        for (char c : availableColors) {
            if (usedColors.find(c) == usedColors.end()) {
                colors[i] = c;
                break;
            }
        }
    }

    // Output the result
    cout << "Colors assigned to each node:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": Color " << colors[i] << endl;
    }
}

int main() {
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> nodes(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u); // Assuming the graph is undirected
    }

    color(nodes);

    return 0;
}
