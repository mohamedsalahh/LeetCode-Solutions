class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows, "");
        
        for(int i = 0; i < s.size();)
        {
            for(int j = 0; j < numRows && i < s.size(); ++j)
                rows[j].push_back(s[i++]);
            
            for(int j = numRows-2; j >= 1 && i < s.size(); --j)
                rows[j].push_back(s[i++]);
        }
        string ans = "";
        for(string& row: rows)
            ans += row;
        return ans;
    }
};