class Solution
{
    public:
    int compareVersion(string version1, string version2)
    {
        // <RMJ.RMN.MJ.MN>
        
        stringstream v1(version1);
        stringstream v2(version2);
        
        // RMJ
        string a1, a2;
        getline(v1, a1, '.');
        getline(v2, a2, '.');
        
        int a1_i = (a1 == "")? 0: stoi(a1);
        int a2_i = (a2 == "")? 0: stoi(a2);
        
        if (a1_i < a2_i)
            return -1;
        else if (a1_i > a2_i)
            return 1;
        
        // RMN
        string b1, b2;
        getline(v1, b1, '.');
        getline(v2, b2, '.');
        
        int b1_i = (b1 == "")? 0: stoi(b1);
        int b2_i = (b2 == "")? 0: stoi(b2);
        
        if (b1_i < b2_i)
            return -1;
        else if (b1_i > b2_i)
            return 1;
             
        // MJ
        string c1, c2;
        getline(v1, c1, '.');
        getline(v2, c2, '.');
        
        int c1_i = (c1 == "")? 0: stoi(c1);
        int c2_i = (c2 == "")? 0: stoi(c2);
        
        if (c1_i < c2_i)
            return -1;
        else if (c1_i > c2_i)
            return 1;
        
        // MN
        string d1, d2;
        getline(v1, d1, '.');
        getline(v2, d2, '.');
        
        int d1_i = (d1 == "")? 0: stoi(d1);
        int d2_i = (d2 == "")? 0: stoi(d2);
        
        if (d1_i < d2_i)
            return -1;
        else if (d1_i > d2_i)
            return 1;
        else
            return 0;
        
        return 0;
    }
};