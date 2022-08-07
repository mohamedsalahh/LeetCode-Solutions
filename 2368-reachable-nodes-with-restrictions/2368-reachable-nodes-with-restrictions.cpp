class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0);
        vector<int> res(n, 0);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int x : restricted)
            res[x] = 1;
        int ans = 0;
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans++;
            for(int v: adj[u])
            {
                if(!vis[v] && !res[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};