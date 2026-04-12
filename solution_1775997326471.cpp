class Solution {
public:
    double myPow(double x, int power) {
        long long n = power;
        if (n < 0){
            n = -n;
            x = 1/x;
        }

        double ans = 1.0;
        while (n > 0){
            if (n & 1) ans = ans*x;
            x = x*x;
            n = n/2;
        }

        return ans;
    }
};


// “Floating-point operations are not exact due to binary representation limitations.”