// GhostCode C++ Env
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--){
        int n; int x;
        cin >> n >> x;
        
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++){
            if (i > 0){
                maxi = max(maxi, arr[i] - arr[i - 1]);
            }
        }

        maxi = max({maxi, arr[0], 2*(x - arr[n - 1])});

        cout << maxi << endl;
    }
    
    return 0;
}