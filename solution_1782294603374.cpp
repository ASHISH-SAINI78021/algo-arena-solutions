#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n = 36;
    vector<int> ans;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            ans.push_back(i);
            if (i != n/i) ans.push_back(n/i);
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}