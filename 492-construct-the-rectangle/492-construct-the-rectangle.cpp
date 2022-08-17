class Solution {
public:
    vector<int> constructRectangle(int area) {
        int diff = INT_MAX;
        vector<int> ans(2);
        for(int i = 1; i * i <= area; ++i)
        {
            if(area % i == 0)
            {
                if(abs(i - (area/i)) < diff)
                {
                    diff = abs(i - (area/i));
                    ans = {i, area/i};
                }
            }
        }
        if(ans[0] < ans[1]) 
            swap(ans[0], ans[1]);
        return ans;
    }
};