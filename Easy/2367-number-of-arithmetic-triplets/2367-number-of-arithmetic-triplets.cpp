class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mp[nums[i] - diff] && mp[nums[i] - 2 * diff])
                ans++;
            mp[nums[i]] = 1;
        }
        return ans;
    }
};