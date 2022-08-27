class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i * i <= num; ++i)
        {
            if(num % i == 0)
            {
                if(num / i == i)
                    sum += i;
                else 
                    sum += i + num / i;
            }
        }
        sum -= num;
        return sum == num;
    }
};