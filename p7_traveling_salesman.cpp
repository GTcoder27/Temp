#include<bits/stdc++.h>
using namespace std;
// Traveling Salesmen's problem

// not completed yet

// int dist[N][N];

// int main()
// {   
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             int x,y,wt;
//             cin>>x>>y>>wt;
//             dist[x][y] = wt;
//         }
//     }
    

//     return 0;
// }


// input
// 0 10 15 20

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

const int INF = INT_MAX;

// Function to solve TSP using DP with bitmasking
int tsp(int mask, int pos, const vector<vector<int>>& dist, vector<vector<int>>& dp) {
    int n = dist.size();
    
    // Base case: All cities visited
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return cost to go back to the starting city
    }

    // Return cached result if available
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INF;

    // Try visiting all unvisited cities
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
