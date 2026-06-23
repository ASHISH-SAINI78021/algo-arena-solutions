#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<pair<long long, int>> a, b, c;
        for (int i = 0; i < n; i++){
            long long x;
            cin >> x;
            a.push_back({x, i});
        }
        for (int i = 0; i < n; i++){
            long long x;
            cin >> x;
            b.push_back({x, i});
        }
        for (int i = 0; i < n; i++){
            long long x;
            cin >> x;
            c.push_back({x, i});
        }

        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());

        long long maxi = 0*1LL;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    if (a[i].second != b[j].second && b[j].second != c[k].second && c[k].second != a[i].second){
                        long long sum = a[i].first + b[j].first + c[k].first;
                        maxi = max(maxi, sum);
                    }
                }
            }
        }

        cout << maxi << endl;
    }
    return 0;
}