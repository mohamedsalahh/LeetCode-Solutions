class Solution
{
public:
    map<string, int> dp;
    bool find(string s, set<string> &wordSet)
    {
        if (s == "")
            return true;
        for (int i = 0; i <= s.size(); ++i)
        {
            if (wordSet.find(s.substr(0, i)) != wordSet.end())
            {
                if (dp.count(s.substr(i)))
                {
                    if (dp[s.substr(i)])
                        return true;
                }
                else
                {
                    dp[s.substr(i)] = find(s.substr(i), wordSet);
                    if (dp[s.substr(i)])
                        return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        return find(s, wordSet);
    }
};