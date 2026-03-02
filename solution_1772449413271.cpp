class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n;
        int start = 0;
        int end = n - 1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (target == arr[mid]){
                ans = mid + 1;
                start = mid + 1;
            }
            else if (target > arr[mid]){
                ans = mid + 1;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};
