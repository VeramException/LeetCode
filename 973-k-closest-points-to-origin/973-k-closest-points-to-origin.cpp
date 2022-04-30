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