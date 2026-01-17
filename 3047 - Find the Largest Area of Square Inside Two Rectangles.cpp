class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxSide = 0;
        int n = bottomLeft.size();

        // Brute force: Iterate through every unique pair of rectangles
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate the intersection
                int inter_min_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                int inter_min_y = max(bottomLeft[i][1], bottomLeft[j][1]);

                
                int inter_max_x = min(topRight[i][0], topRight[j][0]);
                int inter_max_y = min(topRight[i][1], topRight[j][1]);

               
                long long width = max(0, inter_max_x - inter_min_x);
                long long height = max(0, inter_max_y - inter_min_y);

                // If there is a valid intersection (both dimensions > 0)
                if (width > 0 && height > 0) {
                    // The largest square is limited by the smallest dimension
                    long long currentSide = min(width, height);
                    maxSide = max(maxSide, currentSide);
                }
            }
        }

        // Return area (side * side)
        return maxSide * maxSide;
    }
};
