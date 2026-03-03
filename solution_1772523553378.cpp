class Solution {
  public:
    int nthRoot(int n, int m) {
        int start = 1;
        int end  = m;
        int ans = -1;
        if (n == 0) return 1;
        if (m == 0) return 0;
        while (start <= end){
            int mid = start + (end - start)/2;
            long long target = pow(mid,n);
            if (target == m){
                return mid;
            }
            else if (target > m){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
};

// Time Complexity :- O(mlogn)