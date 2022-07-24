class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(pow(2, nums.size()));
        int idx = 0;
        for(int i = 0; i < (1 << nums.size()); ++i)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                if(i & (1 << j))
                    ans[idx].push_back(nums[j]);
            }
            idx++;
        }
        return ans;
    }
};