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
    TreeNode *findMin(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        else if (root->left != NULL)
            return findMin(root->left);
        else
            return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left != NULL && root->right != NULL)
            {
                TreeNode *temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
            else if (root->left == NULL && root->right != NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                root = temp;
            }
        }
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};