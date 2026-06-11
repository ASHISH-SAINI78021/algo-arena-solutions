// GhostCode C++ Env
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n; int m;
        cin >> n >> m;
        string x; string s;
        cin >> x;
        cin >> s;
        bool check = false;

        string t = x;
        int count = 0;
        while (true){
            if (t.find(s) != string::npos){
                cout << count << endl;
                check = true;
                break;
            }
            t = t + t;
            count++;
            if (t.find(s) != string::npos){
                cout << count << endl;
                check = true;
                break;
            }
            else if (t.length() > 25) break ;
        }        
        
        if (!check) cout << -1 << endl;
    }

    return 0;
}