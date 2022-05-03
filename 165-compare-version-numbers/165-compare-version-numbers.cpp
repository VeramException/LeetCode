class Solution
{
    public:
    
    int compare(stringstream& v1, stringstream& v2)
    {
        string a1, a2;
        getline(v1, a1, '.');
        getline(v2, a2, '.');
        
        int v1_i = (a1 == "")? 0: stoi(a1);
        int v2_i = (a2 == "")? 0: stoi(a2);
        
        if (v1_i < v2_i)
            return -1;
        else if (v1_i > v2_i)
            return 1;
        else
            return 0;
    }
    
    int compareVersion(string version1, string version2)
    {
        // <RMJ.RMN.MJ.MN>
        
        stringstream v1(version1);
        stringstream v2(version2);
        
        // RMJ
        int isV1Greater = compare(v1, v2);
        if (isV1Greater == 1 || isV1Greater == -1)
            return isV1Greater;

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
         
        return 0;
    }
};