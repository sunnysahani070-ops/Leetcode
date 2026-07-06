class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();

                int leftSmaller = st.empty() ? -1 : st.top();
                int width = i - leftSmaller - 1;

                maxArea = max(maxArea, 1LL * height * width);
            }
            st.push(i);
        }

        return (int)maxArea;
    }
};