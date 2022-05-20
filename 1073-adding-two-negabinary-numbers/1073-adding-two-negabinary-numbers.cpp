class Solution
{
    public:
    vector<int> addNegabinary(vector<int>& a, vector<int>& b)
    {
        vector<int> res;
        
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        
        while (i>=0 || j>=0 || carry)
        {
            carry += (i>=0)? a[i--]: 0;
            carry += (j>=0)? b[j--]: 0;
            
            res.push_back(carry&1);
            carry = -(carry>>1);
        }
        
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        
        reverse(res.begin(), res.end());
        
        return res;        
    }
};