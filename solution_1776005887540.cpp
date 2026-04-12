class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(long long x, long long n){
        // base case
        if (n == 0) return 1;

        if (n % 2 == 0){
            return solve(x*x % mod, n/2) % mod;
        }
        else return x*solve(x*x % mod, (n - 1)/2) % mod;
    }
    int countGoodNumbers(long long n) {
        // ans = number of even ways * number of odd ways;
        long long evenWays = solve(5, (n + 1)/2) % mod;
        long long oddWays = solve(4, n/2) % mod;

        return (evenWays * oddWays) % mod;
    }
};