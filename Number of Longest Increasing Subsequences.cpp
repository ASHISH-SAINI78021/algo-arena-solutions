#include <bits/stdc++.h>
using namespace std;
// pair<int,int> solve(vector<int> &arr, int index, int prev, vector<vector<int>> &dp, vector<vector<int>> &count){
//     // base case
//     if (index >= arr.size()) return make_pair(0,1);
//     if (dp[index][prev + 1] != -1){
//         return make_pair(dp[index][prev + 1], count[index][prev + 1]);
//     }

//     // solution for one case
//     auto include = make_pair(0,1);
//     int maxlen = 0;
//     int ways = 0;
//     if (prev == -1 || arr[prev] < arr[index]){
//         include = solve(arr, index + 1, index, dp, count);
//         maxlen = include.first + 1;
//         ways = include.second;
//     }
//     auto exclude = solve(arr, index + 1, prev, dp, count);
//     if (exclude.first > maxlen){
//         maxlen = exclude.first;
//         ways = exclude.second;
//     }
//     else if (exclude.first == maxlen){
//         ways += exclude.second;
//     }

//     dp[index][prev + 1] = maxlen;
//     count[index][prev + 1] = ways;

//     return make_pair(maxlen, ways);
// }
int findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();
    int index = 0;
    int prev = -1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> count(n + 1, vector<int>(n + 1, 0));
    for (int prev = -1; prev < n; prev++){
        dp[n][prev + 1] = 0;
        count[n][prev + 1] = 1;
    }

    // fill table bottom-up
    for (int index = n - 1; index >= 0; index--){
        for (int prev = index - 1; prev >= -1; prev--){
            int maxlen = 0;
            int ways = 0;
            if (prev == -1 || arr[prev] < arr[index]){
                int len = 1 + dp[index + 1][index + 1];
                if (len > maxlen){
                    maxlen = len;
                    ways = count[index + 1][index + 1];
                }
                else if (len == maxlen){
                    ways += count[index + 1][index + 1];
                }
            }

            int exclude = dp[index + 1][prev + 1];
            if (exclude > maxlen){
                maxlen = exclude;
                ways = count[index + 1][prev + 1];
            }
            else if (exclude == maxlen){
                ways += count[index + 1][prev + 1];
            }

            dp[index][prev + 1] = maxlen;
            count[index][prev + 1] = ways;
        }
    }

    return count[0][0]; // prev = -1 -> index = 0
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << findNumberOfLIS(arr) << endl;
    return 0;
}