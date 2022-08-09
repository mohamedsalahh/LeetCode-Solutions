class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<bool> inNums1(1001, 0);
        for(int num: nums1)
            inNums1[num] = 1;
        for(int num: nums2)
        {
            if(inNums1[num])
            {
                ans.push_back(num);
                inNums1[num] = 0;
            }
        }
        return ans;
    }
};