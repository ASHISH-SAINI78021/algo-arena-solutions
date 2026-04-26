#include <bits/stdc++.h>
using namespace std;

int maxProfitCooldown(vector<int>& prices) {
    // Write your code here
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfitCooldown(prices) << endl;
    return 0;
}