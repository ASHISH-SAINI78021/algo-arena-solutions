#include <bits/stdc++.h>
using namespace std;

// int solve(vector<vector<int>> &points, int index, int prev, vector<vector<int>> &dp){
//     int n = points.size();
//     if (index >= n){
//         return 0;
//     }
//     if (dp[index][prev] != -1) return dp[index][prev];

//     int ans = INT_MIN;
//     for (int i = 0; i < 3; i++){
//         if (i != prev){
//             int result = solve(points, index + 1, i, dp);
//             if (result != INT_MAX){
//                 ans = max(ans, points[index][i] + result);
//             }
//         }
//     }

//     return dp[index][prev] = ans;
// }
int solve(vector<vector<int>> &points, int prev){
    int n = points.size();
    vector<vector<int>> dp(n + 1, vector<int> (4, 0));

    for (int index = n - 1; index >= 1; index--){
        for (int prev = 2; prev >= 0; prev--){
            int ans = INT_MIN;
            for (int i = 0; i < 3; i++){
                if (i != prev){
                    int result = dp[index + 1][i];
                    if (result != INT_MAX){
                        ans = max(ans, points[index][i] + result);
                    }
                }
            }

            dp[index][prev] = ans;
        }
    }

    return dp[1][prev];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int maxi = 0;
    // vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    for (int i = 0; i < 3; i++){
        maxi = max(maxi, points[0][i] + solve(points, i));
    }
    
    return maxi;
}