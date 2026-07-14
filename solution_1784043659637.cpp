#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--){
        long long n, x, y;
        cin >> n >> x >> y;
        long long count1 = n/x;
        long long count2 = n/y;
        long long lcm = (x/gcd(x,y))*y;
        long long common = n/lcm;
        count1 -= common;
        count2 -= common;

        long long sum = 1LL*n*(n + 1)/2;
        long long sum1 = 1LL*(n - count1)*(n - count1 + 1)/2;
        long long a = sum - sum1;
        long long b = count2*(count2 + 1)/2;

        cout << a - b << endl;
    }
    return 0;
}