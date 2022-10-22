class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        int w;
        int h;
        int area;
        while(left < right){
            h = min(height[left], height[right]);
            w = right-left;
            area = h*w;
            max_area = max(area, max_area);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return max_area;
        
    }
};
