class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int, int> vis;
        vis[n] = 1;
        while(n != 1)
        {
            int next = getSum(n);
            if(vis[next])
                break;
            vis[next] = 1;
            n = next;
        }
        return n == 1;
    }
};