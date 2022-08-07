class Solution {
public:
    
    string intToRoman(int num) {
        string ans = "";
        string n = to_string(num);
        vector<pair<int, char>> v = {{1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'},{10, 'X'}, {5, 'V'}, {1, 'I'}};
        
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
                int vv = 0;
                while(vv < 7)
                {
                    if(v[vv].first <= x)
                    {
                        ans += string(x/v[vv].first, v[vv].second);
                        x %= v[vv].first;
                    }
                    vv++;
                }
            }
        }
        return ans;
    }
};