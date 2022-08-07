class Solution {
public:
    
    string intToRoman(int num) {
        string ans = "";
        string n = to_string(num);
        vector<pair<int, char>> roman = {{1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'},{10, 'X'}, {5, 'V'}, {1, 'I'}};
        
        int m = 1 * pow(10, (int)n.size()-1);
        for(int i = 0 ; i < n.size(); ++i, m/=10)
        {
            int x = (n[i]-'0') * m;
            if(x == 4) ans += "IV";
            else if(x == 9) ans += "IX";
            else if(x == 40) ans += "XL";
            else if(x == 90) ans += "XC";
            else if(x == 400) ans += "CD";
            else if(x == 900) ans += "CM";
            else
            {
                int idx = 0;
                while(idx < 7)
                {
                    if(x >= roman[idx].first)
                    {
                        ans += string(x/roman[idx].first, roman[idx].second);
                        x %= roman[idx].first;
                    }
                    idx++;
                }
            }
        }
        return ans;
    }
};