class Solution {
public:
    vector<int> dp;
    bool solve(int idx, vector<int>& nums)
    {
        if(idx >= nums.size())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        bool ans = 0;
        if(idx <= (int)nums.size()-2)
            if(nums[idx] == nums[idx+1])
                ans = ans || solve(idx+2, nums);
        if(idx <= (int)nums.size()-3)
        {
            if(nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2])
                ans = ans || solve(idx+3, nums);
            if(nums[idx+1] - nums[idx] == 1 && nums[idx+2] - nums[idx+1] == 1)
                ans = ans || solve(idx+3, nums);
        }
        return dp[idx] = ans;
    }
    bool validPartition(vector<int>& nums) {
        dp = vector<int>(nums.size()+1, -1);
        return solve(0, nums);
    }
};