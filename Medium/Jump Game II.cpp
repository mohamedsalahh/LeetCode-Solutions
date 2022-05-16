class Solution
{
public:
    vector<int> dp;
    int solve(int idx, vector<int> &nums)
    {
        if (idx >= nums.size() - 1)
            return 0;

        if (dp[idx] != 1e5)
            return dp[idx];

        for (int i = 1; i <= nums[idx]; ++i)
            dp[idx] = min(dp[idx], solve(i + idx, nums) + 1);
        return dp[idx];
    }
    int jump(vector<int> &nums)
    {
        dp = vector<int>(nums.size(), 1e5);
        return solve(0, nums);
    }
};