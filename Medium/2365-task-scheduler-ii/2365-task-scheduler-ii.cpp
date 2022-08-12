class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int, long long> mp;
        long long ans = 0;
        for(int i = 0; i < tasks.size(); ++i)
        {
            ans++;
            if(mp.count(tasks[i]) != 0 && ans - mp[tasks[i]]  <= space)
                ans += space - (ans - mp[tasks[i]]) + 1;
            mp[tasks[i]] = ans;
        }
        return ans;
    }
};