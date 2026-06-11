class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) st.insert(nums[i]);
        int maxi = 0;

        for (int i = 0; i < n; i++){
            if (st.find(nums[i] - 1) == st.end()){
                int count = 0;
                int num = nums[i];
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