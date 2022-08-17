class Solution {
public:
    void solve(int sum, vector<int> &com, int idx, vector<int>& candidates, int target, set<vector<int>> &ans)
    {
        if(sum > target || idx >= candidates.size())
            return;
        if(sum == target)
        {
            ans.insert(com);
            return;
        }
        solve(sum, com, idx+1, candidates, target, ans);
        com.push_back(candidates[idx]);
        solve(sum+candidates[idx], com, idx, candidates, target, ans);
        solve(sum+candidates[idx], com, idx+1, candidates, target, ans);
        com.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> com;
        solve(0, com, 0, candidates, target, ans);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};