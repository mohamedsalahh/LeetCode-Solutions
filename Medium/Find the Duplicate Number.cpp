class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int freq[100009] = {0};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (freq[nums[i]]++ == 1)
                return nums[i];
        }
        return -1;
    }
};