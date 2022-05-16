/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> s;
            while (sz--)
            {
                Node *temp = q.front();
                q.pop();
                s.push_back(temp->val);
                for (auto child : temp->children)
                {
                    if (child == NULL)
                        continue;
                    q.push(child);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};