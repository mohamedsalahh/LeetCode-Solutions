class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<string> ans;
        int prev = nums[0];
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if((long long) nums[i+1] - nums[i] != 1)
            {
                if(nums[i] == prev)
                    ans.push_back(to_string(nums[i]));
                else
                    ans.push_back(to_string(prev) + "->" + to_string(nums[i]));
                prev = nums[i+1];
            }
        }
        if(prev == nums.back())
            ans.push_back(to_string(nums.back()));
        else
            ans.push_back(to_string(prev) + "->" + to_string(nums.back()));
        return ans;
    }
};