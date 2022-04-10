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
            if (op.find_first_not_of("-0123456789") == std::string::npos)
            {
                scores.push_back(stoi(op));
            }
            else if (op == "+")
            {
                int a = scores[scores.size()-1];
                int b = scores[scores.size()-2];
                scores.push_back(a+b);
            }
            else if (op == "C")
            {
                scores.pop_back();
            }
            else   // op == "D"
            {
                scores.push_back(2*scores.back());
            }            
        }
        
        int res = 0;
        for (int score: scores)
            res += score;
        return res;
    }
};