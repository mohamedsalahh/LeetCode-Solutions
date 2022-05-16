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
    TreeNode *largestNodeOnLeft(TreeNode *root)
    {
        if (root == NULL)
            return root;

        TreeNode *left = largestNodeOnLeft(root->left);
        TreeNode *right = largestNodeOnLeft(root->right);

        if (left == NULL && right == NULL)
            return root;

        TreeNode *large;
        if (left == NULL)
            large = right;
        else if (right == NULL)
            large = left;
        else if (left->val > right->val)
            large = left;
        else
            large = right;

        if (large->val < root->val)
            large = root;
        return large;
    }
    TreeNode *smallestNodeOnLeft(TreeNode *root)
    {
        if (root == NULL)
            return root;

        TreeNode *left = smallestNodeOnLeft(root->left);
        TreeNode *right = smallestNodeOnLeft(root->right);

        if (left == NULL && right == NULL)
            return root;

        TreeNode *small;
        if (left == NULL)
            small = right;
        else if (right == NULL)
            small = left;
        else if (left->val < right->val)
            small = left;
        else
            small = right;

        if (small->val > root->val)
            small = root;
        return small;
    }
    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        int temp;
        TreeNode *left = largestNodeOnLeft(root->left);
        TreeNode *right = smallestNodeOnLeft(root->right);

        if (right != NULL && left != NULL && right->val < left->val)
            swap(right->val, left->val);

        if (left != NULL && left->val > root->val)
            swap(root->val, left->val);

        if (right != NULL && right->val < root->val)
            swap(root->val, right->val);

        recoverTree(root->left);
        recoverTree(root->right);
    }
};