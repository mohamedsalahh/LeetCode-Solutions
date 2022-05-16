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
    vector<vector<pair<int, int>>> child;
    vector<int> par;
    void create(TreeNode *root)
    {
        if (root == NULL)
            return;
        for (auto p : child[root->val])
        {
            if (p.second == 1)
                root->left = new TreeNode(p.first);
            else
                root->right = new TreeNode(p.first);
        }
        create(root->left);
        create(root->right);
    }
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        child = vector<vector<pair<int, int>>>(1e5 + 9);
        par = vector<int>(1e5 + 9);
        int rootVal = 0;
        set<int> st;
        for (auto v : descriptions)
        {
            child[v[0]].push_back({v[1], v[2]});
            par[v[1]] = v[0];
            st.insert(v[0]);
        }
        for (int x : st)
        {
            if (par[x] == 0)
            {
                rootVal = x;
                break;
            }
        }
        TreeNode *root = new TreeNode(rootVal);
        create(root);
        return root;
    }
};