class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCnt = 0;
        for(char c: word)
            if(isupper(c))
                upperCnt++;
        return upperCnt == word.size() || upperCnt == 0 || (upperCnt == 1 && isupper(word[0]));
    }
};