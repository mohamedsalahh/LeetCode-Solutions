class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int oo = 0x3f3f3f3f;
        vector<int> dis(n + 1, oo);
        dis[k] = 0;
        bool isRelaxed = true;
        for (int i = 0; i < n - 1 && isRelaxed; ++i)
        {
            isRelaxed = false;
            for (auto time : times)
            {
                if (dis[time[1]] > dis[time[0]] + time[2])
                {
                    dis[time[1]] = dis[time[0]] + time[2];
                    isRelaxed = true;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            ans = max(ans, dis[i]);
        }
        return (ans == oo ? -1 : ans);
    }
};