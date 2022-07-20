class Solution {
public:
    void solve(int x, int y, vector<string> &ans)
    {
        for(int i = 0; i <= 11; ++i)
        {
            if(__builtin_popcount(i) != x)
                continue;
            string s = to_string(i);
            for(int j = 0; j <= 59; ++j)
            {
                if(__builtin_popcount(j) != y)
                continue;
                if(j <= 9)
                    ans.push_back(to_string(i)+":0"+to_string(j));
                else
                    ans.push_back(to_string(i)+":"+to_string(j));
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i = 0; i <= turnedOn; ++i)
        {
            solve(i, turnedOn-i, ans);
        }
        return ans;
    }
};