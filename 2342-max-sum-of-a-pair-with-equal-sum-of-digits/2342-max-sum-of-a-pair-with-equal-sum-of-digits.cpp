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
        vector<vector<int>> v(90);
        for(int i = 0; i < nums.size(); ++i)
        {
            v[digitsSum(nums[i])].push_back(nums[i]);
        }
        for(int i = 0; i < 90; ++i)
        {
            if(v[i].size() <= 1)
                continue;
            sort(v[i].begin(), v[i].end(), greater<int>());
            ans = max(ans, v[i][0] + v[i][1]);
        }
        return ans;
    }
};