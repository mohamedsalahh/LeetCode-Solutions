class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); ++i)
        {
            freq[s[i]-'a']++;
        }
        for(int i = 0; i < t.size(); ++i)
        {
            if(freq[t[i]-'a'])
                freq[t[i]-'a']--;
            else return t[i];
        }
        return ' ';
    }
};