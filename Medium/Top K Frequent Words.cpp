class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        vector<string> ans;
        priority_queue<pair<int, string>> pq;
        for (string word : words)
        {
            mp[word]++;
        }
        for (auto m : mp)
        {
            pq.push({-m.second, m.first});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};