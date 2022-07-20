class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans = "";
        unsigned int n = num;
        while(n)
        {
            int x = n & 15;
            if(x > 9) ans += x-10+'a';
            else ans += x+'0';
            n >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};