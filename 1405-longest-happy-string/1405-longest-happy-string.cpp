class Solution
{
    public:
    string longestDiverseString(int a, int b, int c)
    {
        string res;
        priority_queue<pair<int, char>> maxHeap;       
        
        vector<pair<int, char>> input = {{a,'a'},{b,'b'},{c,'c'}};
        for (auto const& [count, c]: input)
            if (count != 0)
                maxHeap.push({count, c});
        
        while (!maxHeap.empty())
        {
            auto [count1, c1] = maxHeap.top(); maxHeap.pop();
            
            if (res.size() >= 2 && c1 == res[res.size()-1] && c1 == res[res.size()-2])
            {
                if (maxHeap.empty())
                    break;
                else
                {
                    auto [count2, c2] = maxHeap.top(); maxHeap.pop();
                    res += c2;
                    count2--;
                    if (count2 > 0)
                        maxHeap.push({count2, c2});
                }
            }
            else
            {
                res += c1;
                count1--;
            }
             
            if (count1 > 0)
                maxHeap.push({count1, c1});
        }
        
        return res;
    }
};