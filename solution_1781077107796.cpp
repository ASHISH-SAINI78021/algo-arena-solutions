// GhostCode C++ Env
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--){
        int n; int k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        bool isSorted = true;


        for (int i = 0; i < n; i++){
            if (i > 0 && arr[i] < arr[i - 1]){
                isSorted = false;
                break ;
            }
        }

        if (k == 1 && !isSorted) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}