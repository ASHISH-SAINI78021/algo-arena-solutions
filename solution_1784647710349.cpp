class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;
        if (n == 1) return {nums[0]};
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k && i < n; i++){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        int l = 1;
        int r = l + k - 1;
        while (r < n){
            while (!pq.empty() && pq.top().second < l){
                pq.pop();
            }
            pq.push({nums[r], r});
            ans.push_back(pq.top().first);
            r++;
            l++;
        }

        return ans;
    }
};