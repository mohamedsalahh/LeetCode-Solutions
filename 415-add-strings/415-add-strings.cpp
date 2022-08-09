class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        while(num1 != "" && num2 != "")
        {
            int x = num1.back(), y = num2.back();
            num1.pop_back(); 
            num2.pop_back();
            int sum = x + y - 2 * '0' + carry;
            carry = 0;
            if(sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            ans.push_back(sum + '0');
        }
        string rem;
        if(num1 == "")
            rem = num2;
        else 
            rem = num1;
        while(carry && rem != "")
        {
            int x = rem.back();
            rem.pop_back();
            int sum = x - '0' + carry;
            carry = 0;
            if(sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            ans.push_back(sum + '0');
        }
        if(carry)
            ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return rem + ans;
    }
};