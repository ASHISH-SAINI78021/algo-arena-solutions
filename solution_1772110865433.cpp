class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> arr;
        int n = a.size();
        int m = b.size();
        int i = 0; int j = 0;
        while (i < n && j < m){
            if (a[i] < b[j]){
                arr.push_back(a[i++]);
            }
            else {
                arr.push_back(b[j++]);
            }
        }
        
        while (i < n){
            arr.push_back(a[i++]);
        }
        while (j < m){
            arr.push_back(b[j++]);
        }
        
        vector<int> ans;
        ans.push_back(arr[0]);
        for (int i = 1; i < n + m; i++){
            if (arr[i] != arr[i - 1]){
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};