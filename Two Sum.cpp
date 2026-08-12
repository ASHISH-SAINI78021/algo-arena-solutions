#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] + arr[j] == target){
                return {i, j};
            }
        }
    }

    return {-1,-1};
}

int main() {
    int n, target;
    if (!(cin >> n >> target)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res = twoSum(arr, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}