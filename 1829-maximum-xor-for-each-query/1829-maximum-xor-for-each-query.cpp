class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> bitCount(maximumBit, 0), ans(nums.size(), 0);;
        for(int num: nums)
        {
            for(int i = 0; i < maximumBit; ++i)
                bitCount[i] += (num >> i) & 1;
        }
        
        int idx = nums.size()-1;
        for(int i = 0; i < nums.size(); ++i, --idx)
        {
            int k = 0;
            for(int i = 0; i < maximumBit; ++i)
            {
                if((bitCount[i] & 1) == 0)
                    k |= 1 << i;
            }
            
            for(int i = 0; i < maximumBit; ++i)
                bitCount[i] -= (nums[idx] >> i) & 1;
            ans[i] = k;
        }
        return ans;
    }
};