class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> next(n, -1);
        vector<int> ans(n, 0);
        stack<int> st;


        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if (!st.empty()) next[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++){
            if (next[i] != -1){
                ans[i] = next[i] - i;
            }
        }

        return ans;
    }
};