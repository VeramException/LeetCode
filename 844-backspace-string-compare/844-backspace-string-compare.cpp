class Solution
{
    public:
    bool backspaceCompare(string s1, string s2)
    {
        int i = s1.size()-1;
        int j = s2.size()-1;        
        int back;
        
        while (true)
        {
            back = 0;
            while (i >= 0 && (back > 0 || s1[i] == '#'))
            {
                back = back + (s1[i]=='#'? 1: -1);
                i--;
            }
            
            back = 0;
            while (j >= 0 && (back > 0 || s2[j] == '#'))
            {
                back = back + (s2[j]=='#'? 1: -1);
                j--;
            }
            
            if (i >=0 && j >=0 && s1[i]==s2[j])
            {
                i--;
                j--;
            }
            else
                break;
        }
        
        return (i == -1 && j == -1);
    }
};