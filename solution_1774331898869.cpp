class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto n: nums) {
            freq[n]++;
        }

        for(auto &p: freq) {
            pq.push({p.second, p.first});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};