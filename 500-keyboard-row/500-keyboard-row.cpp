class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> mp;
        vector<string> ans;
        for(char c: "qwertyuiop")
            mp[c] = 1;
        for(char c: "asdfghjkl")
            mp[c] = 2;
        for(char c: "zxcvbnm")
            mp[c] = 3;
        for(string& word: words)
        {
            bool ok = true;
            for(char c: word)
            {
                if(mp[tolower(c)] != mp[tolower(word[0])])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
                ans.push_back(word);
        }
        return ans;
    }
};