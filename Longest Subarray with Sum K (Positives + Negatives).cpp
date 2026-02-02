#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    // Write your code here
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << longestSubarray(arr, k) << endl;
    return 0;
}