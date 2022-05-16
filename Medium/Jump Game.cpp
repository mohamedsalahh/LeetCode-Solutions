class Solution
{
public:
    int dp[10009];
    bool solve(int idx, vector<int> &nums)
    {
        if (idx >= nums.size() - 1)
            return true;

        for (int i = 1; i <= nums[idx]; ++i)
        {
            if (idx + i >= nums.size() - 1)
                return true;
            if (dp[idx + i] == -1)
                dp[idx + i] = solve(i + idx, nums);
            if (dp[idx + i])
                return true;
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};