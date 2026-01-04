class Solution {
public:

    vector<int> get_divisors(int& num) {
        vector<int> res;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                res.push_back(i);
                if (i != num / i) {
                    res.push_back(num / i);
                }
            }
        }
        return res;
    }
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> res = get_divisors(nums[i]);
            if (res.size() == 4) {
                auto result = reduce(res.begin(), res.end());
                total_sum += result;
            }
        }
        return total_sum;
    }
};
