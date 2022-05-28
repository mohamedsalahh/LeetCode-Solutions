class Solution 
{
public:
    string frequencySort(string s) {
        string ans = "";
        vector<int> freq(123, 0);
        for(char c : s)
            freq[c]++;
        
        priority_queue<pair<int, char>> pq;
        for(int i = '0'; i <= 'z'; ++i)
                pq.push({freq[i], (char)i});
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            ans += string(p.first, p.second);
        }
        return ans;
    }
};
