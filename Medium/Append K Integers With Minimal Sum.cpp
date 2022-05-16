class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {
        int n = nums.size() + 2;
        long long ans = 0;
        nums.push_back(0);
        nums.push_back(1000000000);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                continue;
            if ((nums[i + 1] - nums[i] - 1) > k)
            {
                nums[i + 1] = nums[i] + k;
                long long temp1 = ((long long)nums[i] * ((long long)nums[i] + 1)) / 2;
                long long temp2 = ((long long)nums[i + 1] * ((long long)nums[i + 1] + 1)) / 2;
                ans += temp2 - temp1;
                k = 0;
                break;
            }
            else
            {
                nums[i + 1]--;
                long long temp1 = ((long long)nums[i] * ((long long)nums[i] + 1)) / 2;
                long long temp2 = ((long long)nums[i + 1] * ((long long)nums[i + 1] + 1)) / 2;
                ans += temp2 - temp1;
                k -= (nums[i + 1] - nums[i]);
                nums[i + 1]++;
            }
            if (!k)
                break;
        }

        return ans;
    }
};