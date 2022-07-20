class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i < (1 << nums.size()); ++i)
        {
            int x = 0;
            for(int j = 0; j < nums.size(); ++j)
            {
                if((i >> j) & 1)
                    x ^= nums[j];
            }
            ans += x;
        }
        return ans;
    }
};