class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {

        vector<int> ans(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
        {
            int r = startPos[0], c = startPos[1];
            for (int j = i; j < s.size(); ++j)
            {
                if (s[j] == 'L')
                    c--;
                else if (s[j] == 'R')
                    c++;
                else if (s[j] == 'U')
                    r--;
                else
                    r++;
                if (r < 0 || r >= n || c < 0 || c >= n)
                    break;
                ans[i]++;
            }
        }
        return ans;
    }
};