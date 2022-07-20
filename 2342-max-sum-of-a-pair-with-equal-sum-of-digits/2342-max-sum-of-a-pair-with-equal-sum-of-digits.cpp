class Solution {
public:
    int digitsSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<vector<int>> v(90, vector<int>(2, -1));
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > v[digitsSum(nums[i])][0])
                v[digitsSum(nums[i])][0] = nums[i];
            sort(v[digitsSum(nums[i])].begin(), v[digitsSum(nums[i])].end());
        }
        for(int i = 0; i < 90; ++i)
        {
            if(v[i][0] == -1 || v[i][1] == -1)
                continue;
            ans = max(ans, v[i][0] + v[i][1]);
        }
        return ans;
    }
};