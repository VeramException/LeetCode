class Solution
{
    public:
    string simplifyPath(string path)
    {
        vector<string> names;
        
        int i=0, N=path.size();;
        while (i < N)
        {
            if (path[i] == '/')
            {
                while (i<N && path[i] == '/')
                    i++;
            }
            else
            {
                string nextDir;
                while (i<N && path[i]!='/')
                    nextDir += path[i++];
                
                if (nextDir == "..")
                {
                    if(!names.empty())
                        names.pop_back();
                }
                else if (nextDir != ".")
                    names.push_back(nextDir);
            }
        }
        
        string res;
        for (string n: names)
            res += "/" + n;
        
        return res.empty()? "/": res;
    }
};