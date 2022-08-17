class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans, freq(nums.size()+1, 0);
        for(int num: nums)
            freq[num]++;
        for(int i = 1; i <= nums.size(); ++i)
            if(freq[i] == 0)
                ans.push_back(i);
        return ans;
    }
};