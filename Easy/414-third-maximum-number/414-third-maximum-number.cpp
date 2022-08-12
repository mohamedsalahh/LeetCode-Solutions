class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> v(3, LLONG_MIN);
        for(int num: nums)
        {
            if(num == v[0] || num == v[1] || num == v[2])
                continue;
            if(num > v[0])
                v[0] = num;
            sort(v.begin(), v.end());
        }
        return (v[0] != LLONG_MIN? v[0] : v[2]);
    }
};