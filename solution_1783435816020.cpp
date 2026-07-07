#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (n == 2) {
            cout << 1000000000000000000LL << '\n';
            continue;
        }

        for (int bit = 0; bit <= 60; bit++) {
            int zero = 0, one = 0;

            for (long long x : arr) {
                if ((x >> bit) & 1LL)
                    one++;
                else
                    zero++;
            }

            if (zero > 0 && one > 0) {
                cout << (1LL << (bit + 1)) << '\n';
                break;
            }
        }
    }

    return 0;
}