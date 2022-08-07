class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        vector<int> freq(1001, 0);
        for(auto v: items1)
            freq[v[0]] += v[1];
        for(auto v: items2)
            freq[v[0]] += v[1];
        for(int i = 1; i <= 1000; ++i)
            if(freq[i])
                ans.push_back({i, freq[i]});
        return ans;
    }
};