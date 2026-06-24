#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n = 100;
    vector<int> spf(n + 1, -1);
    for (int i = 0; i <= n; i++) spf[i] = i;

    for (int i = 2; i <= n; i++){
        if (spf[i] == i){
            for (int j = i*i; j <= n; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++){
        if (spf[i] == i) cout << i << " ";
    }

    return 0;
}