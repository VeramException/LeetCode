#define x1 0
#define y1 1
#define x2 2
#define y2 3

class Solution
{
    public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        // if they are overlapping
        
        // rec1's bottom-left is always smaller than rec2's top-right,
        // rec2's bottom-left is always smaller than rec1's top-right
        
        return (rec1[x1] < rec2[x2] && rec1[y1] < rec2[y2]) &&
               (rec2[x1] < rec1[x2] && rec2[y1] < rec1[y2]);
    }
};