class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for(int i = 0; i < flowerbed.size(); ++i)
        {
            if(flowerbed[i] == 0)
            {
                if(i - 1 == -1 && i + 1 == flowerbed.size()) cnt++, flowerbed[i] = 1;
                else if(i + 1 == flowerbed.size() && flowerbed[i-1] == 0) cnt++, flowerbed[i] = 1;
                else if(i - 1 == -1 && flowerbed[i+1] == 0) cnt++, flowerbed[i] = 1;
                else if(i - 1 >= 0 && i + 1 < flowerbed.size() && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) cnt++, flowerbed[i] = 1;
            }
            if(cnt >= n)
                return true;
        }
        return false;
    }
};