class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i >= triangle.size() || j >= triangle[i].size() || i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == triangle.size() - 1)
            return triangle[i][j];

        return dp[i][j] = min(solve(i + 1, j + 1, triangle, dp), solve(i + 1, j, triangle, dp)) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};