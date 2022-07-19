class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0^nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            ans ^= nums[i]^i;
        }
        return ans^nums.size();
    }
};