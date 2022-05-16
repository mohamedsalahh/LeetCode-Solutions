class Solution
{
public:
    string simplifyPath(string path)
    {
        string ans = "", temp = "";
        vector<string> dic;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/' && temp == "..")
            {
                if (dic.size() >= 1)
                    dic.pop_back();
                temp = "";
                continue;
            }
            if (path[i] == '/' && temp == ".")
            {
                temp = "";
                continue;
            }

            if (path[i] == '/')
            {
                if (temp == "")
                    continue;
                dic.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(path[i]);
        }
        if (temp != "")
        {
            if (temp == "..")
            {
                if (dic.size() >= 1)
                    dic.pop_back();
            }
            else if (temp != ".")
                dic.push_back(temp);
        }

        for (string str : dic)
            ans += "/" + str;
        if (ans == "")
            return "/";
        return ans;
    }
};