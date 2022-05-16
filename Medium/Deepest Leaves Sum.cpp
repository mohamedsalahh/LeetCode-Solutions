/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, vector<pair<int, int>> &v, int &mx, int d = 0)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            v.push_back({d, root->val});
            mx = max(mx, d);
        }

        solve(root->left, v, mx, d + 1);
        solve(root->right, v, mx, d + 1);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        vector<pair<int, int>> v;
        int mx = INT_MIN;
        int ans = 0;
        solve(root, v, mx);

        for (auto p : v)
        {
            if (p.first == mx)
                ans += p.second;
        }

        return ans;
    }
};