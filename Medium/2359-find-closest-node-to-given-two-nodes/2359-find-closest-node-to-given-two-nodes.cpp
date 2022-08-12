class Solution {
public:
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {        
        int N = edges.size();
        vector<int> dist1(N+1, INT_MAX), dist2(N+1, INT_MAX);;

        int dist = 0, u = node1;
        while(u != -1 && dist1[u] == INT_MAX)
            dist1[u] = dist++, u = edges[u];

        dist = 0;
        u = node2;
        while(u != -1 && dist2[u] == INT_MAX)
            dist2[u] = dist++, u = edges[u];
        
        int min_dest = INT_MAX;
        int ans = -1;
        for(int i = 0; i < N; ++i)
        {
            int mx = max(dist1[i], dist2[i]);
            if(mx < min_dest)
            {
                min_dest = mx;
                ans = i;
            }
        }
        return ans;
    }
};