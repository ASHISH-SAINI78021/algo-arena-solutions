class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> ans;

        for (int i = m - 1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if (!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        for (int i = 0; i < n; i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};


// nums1 = 4 1 2
// nums2 = 1 3 4 2

// 4 -> -1
// 1 -> 3
// 2 -> -1

// Logic
// step1:- traverse from the back
// step2:- we'll use stack to keep track of smaller elements and use unordered map to keep track of nums1 element is present in nums2 or not in O(1) and use ans array to store the answer
// step3:- I'll use stack to check whether the element is smaller present earlier or not