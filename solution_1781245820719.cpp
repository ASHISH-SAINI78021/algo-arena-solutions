class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
       long long s = accumulate(arr.begin(), arr.end(), 1LL*0);
       long long sn = 1LL*n*(n + 1)/2;
       long long s2 = 0;
       for (int i = 0; i < n; i++){
           s2 += 1LL*arr[i]*arr[i];
       }
       long long s2n = 1LL*n*(n + 1)*(2*n + 1)/6;
       
       long long x = 1LL*0.5*(s - sn + ((s2 - s2n)/(s - sn)));
       long long y = 1LL*x - s + sn;
       
       return {x, y};
    }
};