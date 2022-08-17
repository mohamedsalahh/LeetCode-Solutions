class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        string word = "";
        for(char c: s)
        {
            if(c == ' ')
            {
                if(word != "")
                    ans++;
                word = "";
                continue;
            }
            word.push_back(c);
        }
        if(word != "")
            ans++;
        return ans;
    }
};