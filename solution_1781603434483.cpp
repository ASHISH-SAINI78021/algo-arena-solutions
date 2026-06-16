class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);

        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++){
            maxArea = max(maxArea, heights[i]*(nse[i] - pse[i] - 1));
        }


        return maxArea;
    }
};


// heights = 2 1 5 6 2 3
// ple = -1 -1 1 2 1 4
// nle =  1 6 4 4 6 6

// ple[i] = 2
// nle[i] = 4
// nle[i] - ple[i] - 1
// 4 - 2 - 1 = 1