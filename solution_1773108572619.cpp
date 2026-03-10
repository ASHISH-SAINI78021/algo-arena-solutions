class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for (auto it : mp){
            pq.push({it.second, it.first});
        }

        while (k--){
            ans.push_back(pq.top().second);pq.pop();
        }

        return ans;
    }
};


// nums = 1 1 1 2 2 3    k = 2
// 1 -> 3
// 2 -> 2
// 3 -> 1

// o/p -> [1, 2]