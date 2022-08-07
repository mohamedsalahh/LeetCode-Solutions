class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(226, -1);
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mp[s[i]] != -1)
            {
                ans = max(ans, cnt);
                cnt = i - mp[s[i]];
                for(int k = 0; k < 226; ++k)
                {
                    if(mp[k] < mp[s[i]])
                        mp[k] = -1;
                }
                mp[s[i]] = i;
                continue;
            }
            cnt++;
            mp[s[i]] = i;
        }
        ans = max(ans, cnt);
        return ans;
    }
};