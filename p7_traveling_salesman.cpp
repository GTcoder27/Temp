#include<bits/stdc++.h>
using namespace std;
// Traveling Salesmen's problem

const int INF = INT_MAX;

int tsp(int mask, int pos, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    int n = dist.size();
    
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return cost to go back to the starting city
    }

    // Return cached result if available
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // City not visited yet
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            minCost = min(minCost, newCost);
        }
    }

    // Store and return the minimum cost
    return dp[mask][pos] = minCost;
}

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

    // DP table to store results of subproblems
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start TSP from city 0
    int result = tsp(1, 0, dist, dp);

    cout << "Minimum cost of visiting all cities: " << result << endl;

    return 0;
}


// input 
// 4
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
