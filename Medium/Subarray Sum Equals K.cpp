class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0, sum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            int need = sum - k;
            if (mp[need])
                ans += mp[need];
            mp[sum]++;
        }
        return ans;
    }
};