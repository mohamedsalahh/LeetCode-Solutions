struct Edge
{
    int u, v, c;
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.c > b.c;
    }
};

class Solution {
    
    vector<Edge> Prim(vector<vector<Edge>> &adj, int V) 
    {
        priority_queue<Edge, vector<Edge>, cmp> pq;
        vector<Edge> mst;
        vector<int> mstVertex(V, 0); 
        mstVertex[0] = 1;            

        for (Edge e : adj[0]) 
            pq.push(e);

        while (!pq.empty() && mst.size() < V - 1)
        {
            Edge edge = pq.top();
            pq.pop();
            if (mstVertex[edge.u] && mstVertex[edge.v]) 
                continue;

            mst.push_back(edge);

            int notMstVertex = (mstVertex[edge.v] ? edge.u : edge.v); 
            mstVertex[notMstVertex] = 1;

            for (Edge e : adj[notMstVertex])
            {
                if (mstVertex[e.u] && mstVertex[e.v]) 
                    continue;
                pq.push(e);
            }
        }
        return mst;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> v;
        vector<vector<Edge>> adj(n);
        for(int i = 0 ; i < n; ++i)
        {
            for(int j = 0 ; j < n; ++j)
            {
                if(i == j) continue;
                
                Edge e;
                e.u = i;
                e.v = j;
                e.c = abs(points[i][0] - points[j][0]) + abs(points[i][1]- points[j][1]);
                adj[i].push_back(e);
                adj[j].push_back(e);
            }
        }
        
        int ans = 0;
        v = Prim(adj,n);
        for(Edge e : v) ans += e.c;
        return ans;
    }
};



























