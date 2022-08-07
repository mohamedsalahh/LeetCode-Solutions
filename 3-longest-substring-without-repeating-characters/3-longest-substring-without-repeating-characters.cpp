class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            int cnt = 0;
            for(int j = i; j < s.size(); ++j)
            {
                if(mp[s[j]])
                    break;
                cnt++;
                mp[s[j]] = 1;
            }
            mp.clear();
            ans = max(ans, cnt);   
        }
        return ans;
    }
};