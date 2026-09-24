class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        using T = pair<int, int>;
        priority_queue<T> pq; 
        for (int i = 0; i < k && i < n; i++){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        int l = 1;
        int r = k - l + 1;
        while (!pq.empty() && r < n){
            while (!pq.empty() && l > pq.top().second){
                pq.pop();
            }
            pq.push({nums[r], r});
            ans.push_back(pq.top().first);
            l++;
            r++;
        }

        return ans;
    }
};