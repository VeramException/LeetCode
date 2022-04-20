                          // Brute-Force          ||  Time = O(n) --> Technique
                          // [ 0, 0, 0, 0, 0 ]    ||  [ 0,    0,   0,   0,     0]
//update = [1, 3, 2] ==>  // [ 0, 2, 2, 2, 0 ]    ||  [ 0, (+2),   0,   0,  (-2)]  i.e., cummulativeSum => [ 0, 2, 2, 2, 0]
//update = [2, 4, 3] ==>  // [ 0, 2, 5, 5, 3 ]    ||  [ 0,    2, (+3),  0,    -2]  i.e., cummulativeSum => [ 0, 2, 5, 2, 3]
//update = [0, 2, -2] ==> // [-2, 0, 3, 5, 3 ]    ||  [(-2),  2,   3,  0(+2), -2]  i.e., cummulativeSum => [-2, 0, 3, 5, 3]

// In our O(n) technique, I showed cummulative sum at the end of 
// each update, just to show how we can arrive at result for each update.
// However, we have to calculate cummulative sum only at the end (whereever it is required; in this problem at the end of all updates)

// Technique:
// For each update[start, end, val], apply update only at the 'start' index (i.e., res[start] += val),
// and remove that val after the end index to make sure subsequent indices are not effected during cumulative sum.
// i.e., res[end+1] -= val.

class Solution
{
    public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& updates)
    {
        vector<int> res(n, 0);
        
        for (vector<int> update: updates)
        {
            int start = update[0];
            int end   = update[1];
            
            res[start] += update[2];
            
            if (end+1 < n)
                res[end+1] -= update[2];
        }
        
        // cummulative sum
        for (int i=1; i<n; i++)
            res[i] = res[i-1] + res[i];
        
        return res;
    }
};