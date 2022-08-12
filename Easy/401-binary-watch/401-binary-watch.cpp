class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i = 0; i <= 11; ++i)
        {

            for(int j = 0; j <= 59; ++j)
            {
                if(__builtin_popcount(j) + __builtin_popcount(i) != turnedOn)
                    continue;
                
                if(j <= 9)
                    ans.push_back(to_string(i)+":0"+to_string(j));
                else
                    ans.push_back(to_string(i)+":"+to_string(j));
            }
        }
        return ans;
    }
};