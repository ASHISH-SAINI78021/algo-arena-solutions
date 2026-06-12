class Solution {
  public:
    int merge(vector<int> &arr, int start, int mid, int end){
        vector<int> temp;
        long long count = 0;
        int i = start;
        int j = mid + 1;
        while (i <= mid && j <= end){
            if (arr[i] <= arr[j]){
               temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
                count += mid - i + 1;
            }
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= end) temp.push_back(arr[j++]);
        
        for (int i = 0; i < temp.size(); i++){
            arr[start + i] = temp[i];
        }
        
        return count;
    }
    int mergeSort(vector<int> &arr, int start, int end){
        // base case
        if (start >= end){
            return 0;
        }
        
        // solution for one case
        long long inv = 0;
        int mid = start + (end - start)/2;
        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid + 1, end);
        inv += merge(arr, start, mid, end);
        
        return inv;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        long long inv = 0;
        int start = 0;
        int end = n - 1;
        inv = mergeSort(arr, start, end);
        
        return inv;
    }
};