class Solution
{
public:
    double BFS(string src, string des, map<string, vector<string>> &adj, map<pair<string, string>, double> &value)
    {
        map<string, string> par;
        queue<string> q;
        q.push(src);
        par[src] = "";
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            bool f = false;
            for (string v : adj[curr])
            {
                if (par.count(v) == 0)
                {
                    q.push(v);
                    par[v] = curr;
                }
                if (v == des)
                {
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        double res = 1;
        string prev = des;
        des = par[des];
        while (par.count(des) != 0)
        {
            res *= value[{des, prev}];
            prev = des;
            des = par[des];
        }
        if (prev != src)
            return -1.0;
        return res;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, vector<string>> adj;
        map<pair<string, string>, double> value;
        for (int i = 0; i < values.size(); ++i)
        {
            auto v = equations[i];
            adj[v[0]].push_back(v[1]);
            value[{v[0], v[1]}] = values[i];
            adj[v[1]].push_back(v[0]);
            value[{v[1], v[0]}] = 1 / values[i];
        }
        vector<double> ans;
        for (auto q : queries)
        {
            if (q[0] == q[1])
            {
                if (adj.count(q[0]) != 0)
                    ans.push_back(1.0);
                else
                    ans.push_back(-1.0);
                continue;
            }
            double temp = BFS(q[0], q[1], adj, value);
            ans.push_back(temp);
        }
        return ans;
    }
};
