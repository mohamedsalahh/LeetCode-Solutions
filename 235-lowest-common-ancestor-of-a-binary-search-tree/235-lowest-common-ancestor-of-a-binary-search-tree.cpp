/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> getAncestors(TreeNode* root, TreeNode* node)
    {
        vector<TreeNode*> ancestors;
        while(root != node)
        {
            ancestors.push_back(root);
            if(node->val < root->val)
                root = root->left;
            else 
                root = root->right;
        }
        ancestors.push_back(node);
        return ancestors;
    }
    
    bool isChild(TreeNode* root, TreeNode* node)
    {
        if(!root)
            return false;
        if(root == node)
            return true;
        return isChild(root->right, node) || isChild(root->left, node); 
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v = getAncestors(root, p);

        for(int i = v.size()-1; i >= 0; --i)
        {
            if(isChild(v[i], q))
                return v[i];
        }
        return NULL;
    }
};