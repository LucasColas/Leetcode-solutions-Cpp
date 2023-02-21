class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];
        int b = 0;
        int e = nums.size() - 1;
        int m;
        while (b <= e) {
            m = (b+e)/2;
            if ((nums[m] != nums[m-1]) && (nums[m] != nums[m+1])) {
                return nums[m];
            }

            else if ((nums[m] == nums[m+1] && m%2 == 0) || nums[m] == nums[m-1] && m%2 != 0) {
                b = m + 1;
            }

            else {
                e = m-1;
            }
        }

        return nums[b];
    }
};
