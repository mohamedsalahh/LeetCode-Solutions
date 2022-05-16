class cmp
{
public:
    bool operator()(string a, string b) const
    {
        if (a.size() != b.size())
            return a.size() > b.size();
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] == b[i])
                continue;
            else if (a[i] > b[i])
                return true;
            else
                return false;
        }
        return false;
    }
};

class Solution
{
public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, cmp> pq;
        for (string i : nums)
        {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};