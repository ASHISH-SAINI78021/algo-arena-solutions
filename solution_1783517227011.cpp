class Solution {
public:
    bool isSafe(vector<int> &piles, int k, int h){
        int n = piles.size();
        long long hrs = 0;
        for (int i = 0; i < n; i++){
            hrs += 1LL*(piles[i] + k - 1)/k;
        }

        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (start <= end){
            int mid = start + (end - start)/2;
            if (isSafe(piles, mid, h)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};