class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        // x -> repeating number
        // y -> missing number
        long long sn = 1LL*n*(n + 1)/2;
        long long s2n = 1LL*n*(n + 1)*(2*n + 1)/6;
        long long s = accumulate(arr.begin(), arr.end(), 0*1LL);
        long long s2 = 0;
        for (int i = 0; i < n; i++){
            s2 += 1LL*arr[i]*arr[i];
        }
        long long val1 = s - sn; // x - y
        long long val2 = (s2 - s2n)/(s - sn);
        long long x = (val1 + val2)/2;
        long long y = x - val1;
        
        return {x, y};
    }
};