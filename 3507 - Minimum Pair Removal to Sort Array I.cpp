class Solution {
public:
    bool isDecreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }

    int findMinPair(vector<int>& nums) {
        int min_sum = nums[0] + nums[1];
        int index_minpair = 0;
        for (int i = 1; i < nums.size() -1; i++) {
            if (min_sum > nums[i] + nums[i+1]) {
                index_minpair = i;
                min_sum = nums[i] + nums[i+1];
            }
        }
        return index_minpair;
    }

    int minimumPairRemoval(vector<int>& nums) {
        if (isDecreasing(nums)) {
            return 0;
        }
        
        int num_operations = 0;
        int min_pair_index;
        int sum;
        while (!isDecreasing(nums)) {
            min_pair_index = findMinPair(nums);
            sum = nums[min_pair_index] + nums[min_pair_index+1];
            nums.erase(nums.begin() + min_pair_index);
            nums.erase(nums.begin() + min_pair_index);
            nums.insert(nums.begin() + min_pair_index, sum);
            num_operations++;


        }
        return num_operations;
    }
};
