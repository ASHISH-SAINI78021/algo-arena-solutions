// GhostCode C++ Env
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n; int k;
        cin >> n >> k;

        vector<int> arr(n);
        bool check = false;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++){
            if (arr[i] == k){
                cout << "YES" << endl;
                check = true;
                break;
            }
        } 

        if (!check) cout << "NO" << endl;
    }

    return 0;
}