#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp1(n, 1); // LIS
    vector<int> dp2(n, 1); // LDS

    // ✅ LIS from left
    for (int i = 0; i < n; i++){
        for (int prev = 0; prev < i; prev++){
            if (arr[i] > arr[prev]){
                dp1[i] = max(dp1[i], dp1[prev] + 1);
            }
        }
    }

    // ✅ LIS from right (for decreasing)
    for (int i = n - 1; i >= 0; i--){
        for (int prev = n - 1; prev > i; prev--){
            if (arr[i] > arr[prev]){
                dp2[i] = max(dp2[i], dp2[prev] + 1);
            }
        }
    }

    // ✅ Combine
    int maxBitonic = 0;
    for (int i = 0; i < n; i++){
        maxBitonic = max(maxBitonic, dp1[i] + dp2[i] - 1);
    }

    return maxBitonic;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << longestBitonicSubsequence(arr) << endl;
}