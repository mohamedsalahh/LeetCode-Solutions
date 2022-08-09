class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        vector<int> freq('z'+1, 0);
        for(char c: s)
            freq[c]++;
        int odd = 0;
        for(int i = 0; i <= 'z'; ++i)
        {
            ans += (freq[i]/2) * 2;
            freq[i] -= (freq[i]/2) * 2;
            if(freq[i] == 1)
                odd = 1;
        }
        return (odd? ans+1 : ans);
    }
};