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
    bool isEvenOddTree(TreeNode *root)
    {
        int level = 0, levelSize = 1;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int prevElement = (level % 2 ? INT_MAX : INT_MIN);
            int nextLevelSize = 0;
            while (levelSize--)
            {
                TreeNode *node = q.front();
                int val = node->val;
                q.pop();

                if (level % 2)
                {
                    if (val >= prevElement || val % 2)
                        return false;
                }
                else
                {
                    if (val <= prevElement || val % 2 == 0)
                        return false;
                }

                if (node->left != NULL)
                {
                    q.push(node->left);
                    nextLevelSize++;
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                    nextLevelSize++;
                }
                prevElement = val;
            }

            levelSize = nextLevelSize;
            level++;
        }
        return true;
    }
};