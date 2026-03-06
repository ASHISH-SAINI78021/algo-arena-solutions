class Solution {
  public:
    bool isSafe(vector<int> &arr, int maxPages, int k){
        int n = arr.size();
        int count = 1;
        int pages = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] > maxPages) return false;
            if (pages + arr[i] <= maxPages){
                pages += arr[i];
            }
            else {
                count++;
                pages = arr[i];
            }
        }
        
        return count <= k;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        // sort(arr.begin(), arr.end());
        int start = *min_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(arr, mid, k)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
};





// arr = 12 34 67 90    k = 2

// task -> Number of students who can get books which have max pages of m
// pages = min_element(12).......sum(n) => 

// logic -> isSafe()
// count = 1;
// pages + arr[i] <= maxPages -> pages + arr[i] else count++;
// count >= k