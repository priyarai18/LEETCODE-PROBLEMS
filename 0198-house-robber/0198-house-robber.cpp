class Solution {
private:
    int solve(int i, vector<int>& nums, vector<int>& memo) {
        if (i < 0) return 0;
        if (memo[i] != -1) return memo[i];
        int robCurrent = nums[i] + solve(i - 2, nums, memo);
        int skipCurrent = solve(i - 1, nums, memo);
        
        return memo[i] = max(robCurrent, skipCurrent);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(n - 1, nums, memo);
    }
};