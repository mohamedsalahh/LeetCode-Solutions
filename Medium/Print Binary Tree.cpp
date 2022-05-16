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
    int h;

    int H(TreeNode *root)
    {
        if (!root)
            return -1;
        else
            return max(H(root->left), H(root->right)) + 1;
    }

    void dfs(TreeNode *root, int i, int j, vector<vector<string>> &ans)
    {
        if (!root)
            return;
        ans[i][j] = to_string(root->val);
        dfs(root->left, i + 1, j - pow(2, h - i - 1), ans);
        dfs(root->right, i + 1, j + pow(2, h - i - 1), ans);
    }

    vector<vector<string>> printTree(TreeNode *root)
    {
        h = H(root);
        vector<vector<string>> ans(h + 1, vector<string>(pow(2, h + 1) - 1));
        dfs(root, 0, (ans[0].size() - 1) / 2, ans);
        return ans;
    }
};