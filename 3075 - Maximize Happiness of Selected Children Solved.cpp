class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), std::greater<>());
        long long max_happiness = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] - i >= 0) {
                max_happiness += happiness[i] - i;
            }
            
        }
        return max_happiness;
    }
};
