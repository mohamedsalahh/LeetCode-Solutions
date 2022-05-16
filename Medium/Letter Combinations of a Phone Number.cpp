class Solution
{
public:
    void solve(string &digits, string &s, map<int, vector<char>> &mp, vector<string> &ans, int idx = 0)
    {
        if (idx == digits.size())
        {
            ans.push_back(s);
            return;
        }
        for (char c : mp[digits[idx] - '0'])
        {
            s.push_back(c);
            solve(digits, s, mp, ans, idx + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        map<int, vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string s = "";
        solve(digits, s, mp, ans);
        return ans;
    }
};