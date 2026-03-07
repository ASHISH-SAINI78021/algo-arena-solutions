// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxi = 0;
        int ans = -1;
        for (int i = 0; i < n; i++){
            int start = 0;
            int end = m - 1;
            int index = -1;
            while (start <= end){
                int mid = start + (end - start)/2;
                if (arr[i][mid] == 1){
                    index = mid;
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            if (index == -1) continue ;
            if (m - index > maxi){
                maxi = m - index;
                ans = i;
            }
        }
        
        return ans;
    }
};

// Time Complexity :O(n(logm))