class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]].push_back(i);
        }
        for(auto x: mp)
        {
            for(int i = 1; i < x.second.size(); ++i)
            {
                if(x.second[i] - x.second[i-1] <= k)
                    return true;
            }
        }
        return false;
    }
};