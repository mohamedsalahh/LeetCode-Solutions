class Solution {
public:
    bool isPrime(int n)
    {
        if(n == 1 || n == 0) 
            return false;
        for(int i = 2; i * i <= n; ++i)
            if(n % i == 0)
                return false;

        return true;
    }
    
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; ++i)
        {
            int n = i;
            int cnt = 0;
            while(n)
            {
                n &= n-1;
                cnt++;
            }
            
            if(isPrime(cnt))
                ans++;
        }
        return ans;
    }
};