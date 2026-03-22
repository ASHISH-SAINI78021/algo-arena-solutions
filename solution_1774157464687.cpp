class Solution {
public:
    int solve(int n){
        int ans = 0;
        while (n > 0){
            int rem = n % 10;
            ans += rem*rem;
            n = n/10;
        }

        return ans;
    }
    bool isHappy(int n) {
        if (n == 1) return true;
        if (n == 2) return false;
        if (n == 3) return false;
        

        while (n != 1){
            if (n == 4) return false;
            n = solve(n);
        }

        return true;
    }
};