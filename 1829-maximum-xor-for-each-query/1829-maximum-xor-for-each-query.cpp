class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> bitCount(32, 0), ans(nums.size(), 0);;
        for(int num: nums)
        {
            for(int i = 0; i < 32; ++i)
                bitCount[i] += (num >> i) & 1;
        }
        
        int idx = nums.size()-1;
        for(int i = 0; i < nums.size() && idx >= 0; ++i, --idx)
        {
            int k = 0;
            for(int i = 0; i < maximumBit; ++i)
            {
                if((bitCount[i] & 1) == 0)
                    k |= 1 << i;
            }
            
            for(int i = 0; i < 32; ++i)
                bitCount[i] -= (nums[idx] >> i) & 1;
            ans[i] = k;
        }
        return ans;
    }
};