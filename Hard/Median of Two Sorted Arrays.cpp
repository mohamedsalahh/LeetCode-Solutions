class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums;
        int sz = nums1.size() + nums2.size();
        int l1 = 0, l2 = 0;
        int x = sz / 2;
        for (int i = 0; i <= x; ++i)
        {
            if (l1 >= nums1.size())
            {
                nums.push_back(nums2[l2]);
                l2++;
            }
            else if (l2 >= nums2.size())
            {
                nums.push_back(nums1[l1]);
                l1++;
            }
            else if (nums1[l1] <= nums2[l2])
            {
                nums.push_back(nums1[l1]);
                l1++;
            }
            else if (nums1[l1] > nums2[l2])
            {
                nums.push_back(nums2[l2]);
                l2++;
            }
        }
        if (sz % 2)
            return (double)nums.back();
        else
            return (double)(nums[x] + nums[x - 1]) / 2;
    }
};