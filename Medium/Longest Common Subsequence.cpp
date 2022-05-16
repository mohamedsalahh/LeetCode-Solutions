class Solution
{
public:
    int solve(string &s1, string &s2, vector<vector<int>> &dp, int ptr1 = 0, int ptr2 = 0)
    {
        if (ptr1 >= s1.size() || ptr2 >= s2.size())
            return 0;

        if (dp[ptr1][ptr2] != -1)
            return dp[ptr1][ptr2];

        if (s1[ptr1] == s2[ptr2])
            return dp[ptr1][ptr2] = solve(s1, s2, dp, ptr1 + 1, ptr2 + 1) + 1;
        else
            return dp[ptr1][ptr2] = max(solve(s1, s2, dp, ptr1, ptr2 + 1), solve(s1, s2, dp, ptr1 + 1, ptr2));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(1e3 + 7, vector<int>(1e3 + 7, -1));
        return solve(text1, text2, dp);
    }
};