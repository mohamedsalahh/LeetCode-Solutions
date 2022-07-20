class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        int allowedBits = 0;
        
        for(int i = 0; i < allowed.size(); ++i)
        {
            allowedBits |= 1 << (allowed[i] - 'a');
        }
        
        for(string word: words)
        {
            int wordBits = 0;
            for(int i = 0; i < word.size(); ++i)
            {
                wordBits |= 1 << (word[i] - 'a');
            }
            if((allowedBits | wordBits) == allowedBits)
                ans++;
        }
        return ans;
    }
};