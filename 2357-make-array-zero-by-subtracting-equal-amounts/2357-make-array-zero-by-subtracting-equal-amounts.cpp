class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        map<int, int> mp;
        for(int num: nums)
        {
            if(!mp[num] && num != 0)
            {
                cnt++;
                mp[num] = 1;
            }
        }
        return cnt;
    }
};