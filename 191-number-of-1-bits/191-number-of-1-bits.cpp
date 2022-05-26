class Solution
{
    public:
    int hammingWeight(uint32_t n)
    {
        // __builtin_popcount = int
        // __builtin_popcountl = long int
        // __builtin_popcountll = long long
        
        return __builtin_popcount(n);
        
        //return bitset<32>(n).count();        
    }
};