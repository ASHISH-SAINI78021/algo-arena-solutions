// GhostCode C++ Env
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[arr[i]]++;

        if (mp.size() == 1){
            cout << "YES" << endl;
        }
        else if (mp.size() == 2){
            vector<int> temp;
            for (auto it : mp){
                temp.push_back(it.second);
            }

            if (abs(temp[0] - temp[1]) > 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
            
    }

    return 0;
}