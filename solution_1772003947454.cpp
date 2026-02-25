class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return -1;
        int maxi = *max_element(arr.begin(), arr.end());
        int second = -1;
        for (int i = 0; i < n; i++){
            if (arr[i] > second && arr[i] != maxi){
                second = arr[i];
            }
        }
        
        return second;
    }
};