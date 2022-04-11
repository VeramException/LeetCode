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
            // ".."
            else if ((i == N-2 && path[i] == '.' && path[i+1] == '.') ||
                    (i < N-2 && path[i] == '.' && path[i+1] == '.' && path[i+2] == '/'))
            {
                if (!names.empty())
                    names.pop_back();
                i = i+2;
            }
            else if ((i==N-1 && path[i]=='.') ||
                     (i<N-1 && path[i]=='.' && path[i+1]=='/'))
            {
                i++;
            }
            else
            {
                string name;
                while (i<N && path[i] != '/')
                {
                    name.push_back(path[i]);
                    i++;
                }
                names.push_back(name);
            }
        }
        
        string res;
        for (string n: names)
            res += "/" + n;
        
        return res.empty()? "/": res;
    }
};