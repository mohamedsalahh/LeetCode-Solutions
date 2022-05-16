class Solution
{
public:
    bool solve(string &s1, string &s2, string &s3, int ptr1, int ptr2, int ptr3, vector<vector<int>> &dp)
    {
        if (ptr3 == s3.size())
        {
            if (ptr1 == s1.size() && ptr2 == s2.size())
                return true;
            else
                return false;
        }
        if (ptr1 >= s1.size() && ptr2 >= s2.size())
            return false;

        if (dp[ptr1][ptr2] != -1)
            return dp[ptr1][ptr2];
        bool ans = false;

        if (s1[ptr1] == s3[ptr3])
            ans = ans || solve(s1, s2, s3, ptr1 + 1, ptr2, ptr3 + 1, dp);

        if (s2[ptr2] == s3[ptr3])
            ans = ans || solve(s1, s2, s3, ptr1, ptr2 + 1, ptr3 + 1, dp);

        return dp[ptr1][ptr2] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> dp(110, vector<int>(110, -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};