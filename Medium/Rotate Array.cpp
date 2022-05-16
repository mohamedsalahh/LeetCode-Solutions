class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> temp = nums;
        int n = nums.size();
        k %= n;
        int idx = 0;
        for (int i = n - k; i < n; ++i)
            nums[idx++] = temp[i];
        for (int i = 0; i < n - k; ++i)
            nums[idx++] = temp[i];
    }
};