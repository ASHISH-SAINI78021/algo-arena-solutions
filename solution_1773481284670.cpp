class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ple(n, -1);
        vector<int> nle(n, n);

        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (!st.empty()) ple[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (!st.empty()) nle[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++){
            int width = nle[i] - ple[i] - 1;
            int area = heights[i]*width;
            maxArea = max(area, maxArea);
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