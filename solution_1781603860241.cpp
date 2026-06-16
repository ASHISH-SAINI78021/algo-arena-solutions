class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> st;
        st.push(-1);  // Initialize stack with -1 for boundary condition
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();  // Store the index of the previous smaller element
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        stack<int> st;
        st.push(-1);  // Initialize stack with -1 for boundary condition
        vector<int> ans(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();  // Store the index of the next smaller element
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        // Step 1: Get the previous smaller elements
        vector<int> prev = prevSmaller(heights);

        // Step 2: Get the next smaller elements
        vector<int> next = nextSmaller(heights);

        int maxArea = 0;  // Initialize maxArea to 0

        // Step 3: Calculate the largest rectangle area
        for (int i = 0; i < heights.size(); i++) {
            if (next[i] == -1) {
                next[i] = heights.size();  // Handle case when there is no next smaller element
            }
            int len = heights[i];  // Height of the current bar
            int width = next[i] - prev[i] - 1;  // Width of the rectangle
            int area = len * width;  // Calculate the area
            maxArea = max(area, maxArea);  // Update maxArea if current area is larger
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        int maxRectangle = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }

        return maxRectangle;
    }
};