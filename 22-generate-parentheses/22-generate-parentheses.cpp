class Solution {
public:
    set<string> st;
    void solve(string s, int open, int n)
    {
        if(open < 0)
            return;
        if(n == 0)
        {
            if(open == 0)
                st.insert(s);
            return;
        }
        solve(s+"(", open+1, n-1);
        solve(s+")", open-1, n-1);
    }
    vector<string> generateParenthesis(int n) {
        solve("", 0, 2*n);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};