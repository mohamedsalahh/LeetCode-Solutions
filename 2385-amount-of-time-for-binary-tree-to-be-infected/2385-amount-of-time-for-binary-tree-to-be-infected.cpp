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
    TreeNode* startNode = NULL;
    unordered_map<TreeNode*, TreeNode*> par;
    void dfs(TreeNode* root, TreeNode* parent, int start)
    {
        if(root == NULL)
            return;
        if(root->val == start)
            startNode = root;
        par[root] = parent;
        dfs(root->left, root, start);
        dfs(root->right, root, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, NULL, start);
        unordered_map<TreeNode*, int> vis;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = 1;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL && !vis[node->left])
                    q.push(node->left), vis[node->left] = 1;
                if(node->right != NULL && !vis[node->right])
                    q.push(node->right), vis[node->right] = 1;
                if(par[node] != NULL && !vis[par[node]])
                    q.push(par[node]), vis[par[node]] = 1;
                
            }
        }
        return ans-1;
    }
};