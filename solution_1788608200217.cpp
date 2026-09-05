class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : mp){
            pq.push({it.second, it.first});
        }

        if (k > mp.size()) return ans;

        while (k-- && !pq.empty()){
            auto top = pq.top(); pq.pop();
            int element = top.second;
            ans.push_back(element);
        }

        return ans;
    }
};