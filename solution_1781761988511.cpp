class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int i = 0; i < n && i < k; i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() && k--){
            auto top = pq.top(); pq.pop();
            int first = top.second.first;
            int second = top.second.second;

            ans.push_back({nums1[first], nums2[second]});

            if (second + 1 < m){
                pq.push({nums1[first] + nums2[second + 1], {first, second + 1}});
            }
        }


        return ans;
    }
};