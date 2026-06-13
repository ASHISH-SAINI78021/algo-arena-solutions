class Solution {
  public:
    bool isSafe(vector<int> &stalls, int dis, int k){
        int n = stalls.size();
        int prevStall = stalls[0];
        int count = 1;
        for (int i = 1; i < n; i++){
            if (stalls[i] - prevStall >= dis){
                count++;
                prevStall = stalls[i];
            }
        }
        
        return count >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        int ans = -1;
        sort(stalls.begin(), stalls.end());
        int start = 1;
        int end = stalls[n - 1];
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(stalls, mid, k)){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};