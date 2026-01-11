class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> s;
        int maxA = 0;
        int n = heights.size();

        
        for (int i = 0; i <= n; ++i) {
           
            int currentHeight = (i == n) ? 0 : heights[i];

            // Monotonic Stack: maintain increasing heights.
            // If current bar is shorter, pop the taller bars from stack.
            while (!s.empty() && currentHeight < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                
                // Determine width: from the new top of stack to current index i
                int width = s.empty() ? i : i - s.top() - 1;
                maxA = max(maxA, h * width);
            }
            s.push(i);
        }
        return maxA;
    }
};
