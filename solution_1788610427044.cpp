class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k && i < n; i++) pq.push({nums[i], i});
        ans.push_back(pq.top().first);
        
        int l = 1;
        int r = k - l + 1;
        while (r < n){
            while (!pq.empty() && pq.top().second < l){
                pq.pop();
            }
            pq.push({nums[r], r});
            l++;
            r++;
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};