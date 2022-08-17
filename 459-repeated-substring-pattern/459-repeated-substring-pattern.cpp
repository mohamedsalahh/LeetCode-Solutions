class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 1)
            return false;
        for(int i = s.size()-1; i >= s.size()/2; --i)
        {
            if(s[i] == s[0])
            {
                string substring = s.substr(i);
                if((int)s.size()%(int)substring.size() != 0)
                    continue;
                bool isOk = true;
                for(int j = 0; j < s.size() - substring.size(); j += substring.size())
                {
                    if(substring != s.substr(j, substring.size()))
                    {
                        isOk = false;
                        break;
                    }
                }
                if(isOk)
                    return true;
            }
        }
        return false;
    }
};