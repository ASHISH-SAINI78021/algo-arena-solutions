class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size();
        long long actualSum = accumulate(arr.begin(), arr.end(), 0LL);
        long long sum = 1LL*(n + 1)*(n + 2)/2;
        return abs(sum - actualSum);
    }
};