class Solution {
public:
    void solve(int sum, vector<int> &combination, int idx, vector<int>& candidates, int target, vector<vector<int>> &ans)
    {
        if(sum == target) {
            ans.push_back(combination);
            return;
        }
        
        if(sum > target || idx >= candidates.size())
            return;
        solve(sum, combination, idx+1, candidates, target, ans);
        combination.push_back(candidates[idx]);
        solve(sum+candidates[idx], combination, idx, candidates, target, ans);
        combination.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        solve(0, combination, 0, candidates, target, ans);
        return ans;
    }
};