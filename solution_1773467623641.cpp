class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int maxi = 0;
        for (int i = 0; i < n; i++) st.insert(nums[i]);
        

        for (int i = 0; i < n; i++){
            int num = nums[i] - 1;
            if (st.find(num) == st.end()){
                int count = 0;
                while (st.find(num + 1) != st.end()){
                    count++;
                    num++;
                }
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};