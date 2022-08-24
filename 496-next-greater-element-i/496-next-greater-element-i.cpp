class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> idx(1e4+1);
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums2.size(); ++i)
            idx[nums2[i]] = i;
        for(int i = 0 ; i < nums1.size(); ++i)
        {
            for(int j = idx[nums1[i]]; j < nums2.size(); ++j)
            {
                if(nums2[j] > nums1[i])
                {
                    ans[i] = nums2[j];
                    break;
                }
                
            }
        }
        return ans;
    }
};