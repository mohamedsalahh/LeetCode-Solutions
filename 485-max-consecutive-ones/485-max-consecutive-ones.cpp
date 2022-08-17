class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int prev = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                ans = max(ans, i - prev - 1);
                prev = i;
            }
        }
        ans = max(ans, (int)nums.size() - prev - 1);
        return ans;
    }
};