class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (auto it : nums) st.insert(it);
        int maxi = 0;


        for (int i = 0; i < n; i++){
            int num = nums[i];
            if (st.find(num - 1) == st.end()){
                num = num + 1;
                int count = 1;
                while (st.find(num) != st.end()){
                    count++;
                    num = num + 1;
                }
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};