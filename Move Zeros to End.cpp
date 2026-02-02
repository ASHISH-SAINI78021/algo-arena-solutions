#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int>& arr) {
    int n = arr.size();
    int k = 0;
    for (int i = 0; i < n; i++){
int nonZeroIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            arr[nonZeroIndex++] = arr[i];
        }
    }
    while (nonZeroIndex < n) {
        arr[nonZeroIndex++] = 0;
    }
        if (arr[i] == 0){
            k = i; break;
        }
    }
    
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    moveZeros(arr);
    for(int i=0; i<n; i++) cout << arr[i] << (i==n-1 ? "" : " ");
    cout << endl;
    return 0;
}