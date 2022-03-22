class Solution
{
    public:
    string originalDigits(string s)
    {
        vector<int> charFreq(26, 0);
        for (char c: s)
            charFreq[c - 'a']++;
        
        vector<int> nums(10, 0);
        
        // Set-1: Indepedent
        nums[0] = charFreq['z' - 'a'];                                  // 'z' occurs only in 0
        nums[2] = charFreq['w' - 'a'];                                  // 'w' occurs only in 2
        nums[4] = charFreq['u' - 'a'];                                  // 'u' occurs only in 4
        nums[6] = charFreq['x' - 'a'];                                  // 'x' occurs only in 6
        nums[8] = charFreq['g' - 'a'];                                  // 'g' occurs only in 8
        
        // Set-2: based on Set-1
        nums[1] = charFreq['o' - 'a'] - nums[0] - nums[2] - nums[4];    // 'o' occurs in 1 & 0,2,4
        nums[3] = charFreq['r' - 'a'] - nums[0] - nums[4];              // 'r' occurs in 3 & 0,4
        nums[7] = charFreq['s' - 'a'] - nums[6];                        // 's' occurs in 7 & 6
        
        // Set-3: based on Set-2
        nums[5] = charFreq['v' - 'a'] - nums[7];                        // 'v' occurs in 5 & 7
        
        // Set-4: based on Set-3
        nums[9] = charFreq['i' - 'a'] - nums[5] - nums[6] - nums[8];    // 'i' occurs in 9 & 5,6,8
        
        string res;
        for (int i=0; i<10; i++)
            while (nums[i] != 0 && nums[i]-- != 0)
                res += to_string(i);
        return res;
    }
};