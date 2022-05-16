class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;
        while (x != 0)
        {
            int y = x % 10;
            x /= 10;
            if ((long long)ans * 10 + y > INT_MAX || (long long)ans * 10 + y < INT_MIN)
                return 0;
            ans = ans * 10 + y;
        }
        return ans;
    }
};