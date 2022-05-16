class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> graph(n);
        const int MAX = 1e7;
        for (auto &e : redEdges)
            graph[e[0]].push_back({e[1], 1});

        for (auto &e : blueEdges)
            graph[e[0]].push_back({e[1], -1});

        vector<int> dRed(n, MAX), dBlue(n, MAX);
        dRed[0] = 0;
        dBlue[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &[child, color] : graph[node])
            {
                if (color == 1 && dBlue[node] + 1 < dRed[child])
                {
                    dRed[child] = dBlue[node] + 1;
                    q.push(child);
                }
                else if (color == -1 && dRed[node] + 1 < dBlue[child])
                {
                    dBlue[child] = dRed[node] + 1;
                    q.push(child);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int temp = min(dRed[i], dBlue[i]);
            ans.push_back((temp == MAX) ? -1 : temp);
        }
        return ans;
    }
};