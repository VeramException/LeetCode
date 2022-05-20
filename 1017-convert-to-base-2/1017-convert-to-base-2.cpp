class Solution
{
    public:
    string baseNeg2(int n)
    {
        string res = "";
        while (n != 0)
        {
            res = to_string(n & 1) + res;
            n = -(n >> 1);
        }
        return res == "" ? "0" : res;
    }
};