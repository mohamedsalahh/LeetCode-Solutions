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
class Solution {
public:
    TreeNode* construct(int l, int r, vector<int>& nums)
    {
        if(r < l) return NULL;
        if(r == l) return new TreeNode(nums[r]);
        
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct(l, mid-1, nums);
        root->right = construct(mid+1, r, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(0, nums.size()-1, nums);
    }
};