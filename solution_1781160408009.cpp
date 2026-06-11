// GhostCode C++ Env
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s(n, '.');
        cin >> s;
        bool check = false;
        int count = 0;
    
        for (int i = 0; i < n; i++){
            if (s[i] == '.') count++;
            if (i > 0 && i < n - 1 && s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.'){
                cout << 2 << endl;
                check = true;
                break;
            }
        }
        
        if (!check) cout << count << endl;
            
    }

    return 0;
}