class Solution {
public:
    void solve(string s, int openBrackets, int n, vector<string>& ans)
    {
        if(openBrackets < 0)
            return;
        if(n == 0)
        {
            if(openBrackets == 0)
                ans.push_back(s);
            return;
        }
        solve(s+"(", openBrackets+1, n-1, ans);
        solve(s+")", openBrackets-1, n-1, ans);
    }
    vector<string> generateParenthesis(int n) {
         vector<string> ans;
        solve("", 0, 2*n, ans);
        return ans;
    }
};