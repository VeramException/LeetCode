// There are 2 cities - A & B.
//
// [p,q],[r,s],[t,u]
//   0     1     2
//
// Cost of sending 0 person to A => p
// Cost of sending 0 person to B => q
// Cost of sending 1 person to A => r
// Cost of sending 1 person to B => s
// Cost of sending 2 person to A => t
// Cost of sending 3 person to B => u
//
// What is the minimum cost of sending half people to city-A and half people to city-B
//
// PS: number of candidates is always EVEN

class Solution
{
    public:
    
    // Return 'true' if picking city-A in c1 gives more savings than picking city-A in c2
    static bool compareSavings(vector<int>& c1, vector<int>& c2)
    {
        return (c1[1] - c1[0]) > (c2[1] - c2[0]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        // sort the 'costs' such that the savings of picking city A is <high ...... less>
        sort(costs.begin(), costs.end(), compareSavings);
        
        int res = 0;
        int N = costs.size();
        for (int i=0, j=N-1; i<N/2; i++,j--)
            res += costs[i][0] + costs[j][1];
        return res;
    }
};