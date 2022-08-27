class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> rank;
        vector<int> temp = score;
        sort(temp.begin(), temp.end(), greater<int>());
        vector<string> ans;
        for(int i = 0; i < temp.size(); ++i)
            rank[temp[i]] = i+1;
        for(int i = 0 ; i < score.size(); ++i)
        {
            if(rank[score[i]] == 1)
                ans.emplace_back("Gold Medal");
            else if(rank[score[i]] == 2)
                ans.emplace_back("Silver Medal");
            else if(rank[score[i]] == 3)
                ans.emplace_back("Bronze Medal");
            else 
                ans.emplace_back(to_string(rank[score[i]]));
        }
        return ans;
    }
};