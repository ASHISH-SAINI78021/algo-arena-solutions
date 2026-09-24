class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return {};
        if (n == 1) return nums;
        vector<int> ans;
        unordered_map<int, int> mp;
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for (auto it : mp){
            if (pq.size() < k){
                pq.push({it.second, it.first});
            }
            else if (it.second > pq.top().first){
                pq.pop();
                pq.push({it.second, it.first});
            }
        }

        while (!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }

        return ans;        
    }
};