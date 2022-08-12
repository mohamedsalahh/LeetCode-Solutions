class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        map<int, long long> mp;
        for (int i = 0; i < nums.size(); i++) {
            ans += i - mp[nums[i] - i];
            mp[nums[i] - i]++;
        }
        return ans;
    }
};