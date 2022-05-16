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
    bool checkleft(TreeNode *root, int val)
    {
        if (root == NULL)
            return true;
        if (root->val < val)
            return checkleft(root->left, val) && checkleft(root->right, val);
        return false;
    }
    bool checkright(TreeNode *root, int val)
    {
        if (root == NULL)
            return true;
        if (root->val > val)
            return checkright(root->left, val) && checkright(root->right, val);
        return false;
    }
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (checkleft(root->left, root->val) && checkright(root->right, root->val))
            return isValidBST(root->left) && isValidBST(root->right);
        return false;
    }
};