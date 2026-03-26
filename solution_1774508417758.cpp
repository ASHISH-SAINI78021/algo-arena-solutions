class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for (auto it : mp){
            pq.push({it.second, it.first});
            if (pq.size() > k){
                pq.pop();
            }
        }

        while (!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }

        return ans;
    }
};