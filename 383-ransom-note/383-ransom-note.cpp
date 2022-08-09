class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for(char c: magazine)
            freq[c-'a']++;
        for(char c: ransomNote)
        {
            if(freq[c-'a'])
                freq[c-'a']--;
            else 
                return false;
        }
        return true;
    }
};