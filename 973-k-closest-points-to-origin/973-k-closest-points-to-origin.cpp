class Solution
{
    public:
    
    static bool customCompare(vector<int> a, vector<int> b)
    {
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        sort(points.begin(), points.end(), customCompare);
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

// The above will sort all points O(n Log(n)).

// But it is enough that we sort just first 'k' elements right? O(n Log(k))
// Following is 'partial_sort' which will just sort first 'k' elements

/*

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
         partial_sort(points.begin(), 
                      points.begin() + k, 
                      points.end(), 
                      [](vector<int>& p, vector<int>& q) { return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1]; });
                         
         return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

*/