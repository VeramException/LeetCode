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
        
        int i = 4;
        while (i-- > 0)
        {
            int isV1Greater = compare(v1, v2);
            if (isV1Greater == 1 || isV1Greater == -1)
                return isV1Greater;
        }
         
        return 0;
    }
};