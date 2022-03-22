class Solution
{
    public:
    string originalDigits(string s)
    {
        vector<int> charFreq(26, 0);
        for (char c: s)
            charFreq[c - 'a']++;
        
        vector<int> nums(10, 0);
        
        nums[0] = charFreq['z' - 'a'];
        nums[2] = charFreq['w' - 'a'];
        nums[4] = charFreq['u' - 'a'];
        nums[6] = charFreq['x' - 'a'];
        nums[8] = charFreq['g' - 'a'];
        
        nums[1] = charFreq['o' - 'a'] - nums[0] - nums[2] - nums[4];
        nums[3] = charFreq['r' - 'a'] - nums[0] - nums[4];
        nums[7] = charFreq['s' - 'a'] - nums[6];        

        nums[5] = charFreq['v' - 'a'] - nums[7];
        
        nums[9] = charFreq['i' - 'a'] - nums[5] - nums[6] - nums[8];
        
        string res;
        for (int i=0; i<10; i++)
        {
            while (nums[i] != 0 && nums[i]-- != 0)
                res += to_string(i);
        }
        return res;
    }
};