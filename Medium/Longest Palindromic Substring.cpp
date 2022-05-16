class Solution
{
public:
    pair<int, int> longest(string s, int idx)
    {
        int l = idx - 1, r = idx + 1;
        if (idx + 1 < s.size() && s[idx] == s[idx + 1])
        {
            r++;
            while (r < s.size() && l >= 0 && s[l] == s[r])
            {
                l--;r++;
            }
        }

        int ll = idx - 1, rr = idx + 1;
        while (rr < s.size() && ll >= 0 && s[ll] == s[rr])
        {
            ll--;rr++;
        }
        ++l;++ll;--r;--rr;
        if ((r - l + 1) > (rr - ll + 1))
            return {l, r};
        else
            return {ll, rr};
    }
    string longestPalindrome(string s)
    {
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto p = longest(s, i);
            if ((p.second - p.first + 1) > (r - l + 1))
            {
                l = p.first;
                r = p.second;
            }
        }
        return s.substr(l, r - l + 1);
    }
};