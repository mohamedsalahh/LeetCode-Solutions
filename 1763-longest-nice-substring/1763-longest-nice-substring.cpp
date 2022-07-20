class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = i; j < s.size(); ++j)
            {
                vector<int> freq1(26, 0), freq2(26, 0);
                string temp = s.substr(i, j-i+1);
                
                for(int k = 0; k < temp.size(); ++k)
                    if(temp[k] >= 'a')
                        freq1[temp[k]-'a'] = 1;
                
                for(int k = 0; k < temp.size(); ++k)
                    if(temp[k] <= 'Z')
                        freq2[temp[k]-'A'] = 1;

                bool isNice = true;
                
                for(int i = 0; i < 26; ++i)
                    if(freq1[i] != freq2[i])
                        isNice = false;

                if(isNice && temp.size() > ans.size())
                    ans = temp;
            }
        }
        return ans;
    }
};