class Solution
{
    public:
    int calPoints(vector<string>& ops)
    {
        int prev1;
        int prev2;
        
        // prev1, prev2, curr
        
        vector<int> scores;
        for (string op: ops)
        {
            if (op == "+")
            {
                int a = scores[scores.size()-1];
                int b = scores[scores.size()-2];
                scores.push_back(a+b);
            }
            else if (op == "C")
            {
                scores.pop_back();
            }
            else if (op == "D")
            {
                scores.push_back(2*scores.back());
            }
            else
            {
                scores.push_back(stoi(op));
            }
        }
        
        int res = 0;
        for (int score: scores)
            res += score;
        return res;
    }
};