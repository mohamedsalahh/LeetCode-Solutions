class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        if (arr[start] == 0)
            return true;
        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(start);
        vis[start] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            int v1 = u + arr[u], v2 = u - arr[u];
            if (v1 >= 0 && v1 < n && !vis[v1])
            {
                if (arr[v1] == 0)
                    return true;
                q.push(v1);
                vis[v1] = 1;
            }
            if (v2 >= 0 && v2 < n && !vis[v2])
            {
                if (arr[v2] == 0)
                    return true;
                q.push(v2);
                vis[v2] = 1;
            }
        }
        return false;
    }
};