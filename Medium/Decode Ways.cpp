class Solution
{
public:
    vector<int> dp;
    int solve(string s, int idx = 0)
    {
        if (dp[idx] != -1)
            return dp[idx];

        if (s[idx] == '0')
            return dp[idx] = 0;
        if (idx >= s.size() - 1)
            return dp[idx] = 1;

        int ans = solve(s, idx + 1);
        if (s[idx] == '2' && s[idx + 1] <= '6' || s[idx] == '1' && s[idx + 1] <= '9')
            ans += solve(s, idx + 2);
        return dp[idx] = ans;
    }
    int numDecodings(string s)
    {
        dp = vector<int>(109, -1);
        return solve(s);
    }
};