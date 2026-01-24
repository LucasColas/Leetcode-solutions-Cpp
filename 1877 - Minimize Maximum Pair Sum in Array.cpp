class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_pair = 0;
        int length = nums.size();
        for (int i = 0; i < length / 2; i++) {
            if (nums[i] + nums[length-1-i] > max_pair) {
                max_pair = nums[i] + nums[length-1-i];
            }
        }

        return max_pair;
    }
};
