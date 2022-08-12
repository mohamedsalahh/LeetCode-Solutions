class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber)
        {
            ans.push_back((columnNumber - 1) % 26 + 'A');
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};