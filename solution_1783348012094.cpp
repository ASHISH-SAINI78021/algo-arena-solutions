#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        using T = pair<long long, int>;
        vector<T> a(n);
        vector<T> b(n);
        vector<T> c(n);

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

        long long maxi = LLONG_MIN;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    int x = a[i].second; int y = b[j].second; int z = c[k].second;
                    if (x != y && y != z && z != x){
                        maxi = max(maxi, a[i].first + b[j].first + c[k].first);
                    }
                }
            }
        }

        cout << maxi << endl;
    }
    return 0;
}
















