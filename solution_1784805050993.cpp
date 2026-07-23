class Solution {
public:
    bool isSafe(vector<int> &piles, long long k, int h){
        long long hrs = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++){
            hrs += 1LL*(piles[i] + k - 1)/k;
        }

        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long start = 1;
        long long end = *max_element(piles.begin(), piles.end());
        long long ans = -1;

        while (start <= end){
            long long mid = start + (end - start)/2;
            if (isSafe(piles, mid, h)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return ans;
    }
};