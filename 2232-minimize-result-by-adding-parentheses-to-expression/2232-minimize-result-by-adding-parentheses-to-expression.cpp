class Solution
{
public:
    string minimizeResult(string exp)
    {
        int maxVal = INT_MAX;
        string res;

        // Step-0: Get index of '+'
        int plus = exp.find('+');
        int N = exp.size();

        // Step-1: Consider all possibilities,
        //         and evaluate expression
        for (int i = 0; i < plus; i++)           // Try '(' at 0 to plus-1 positions
        {
            for (int j = plus + 1; j < N; j++)   // Try ')' at plus+1 to N-1 positions
            {
                // 12(3+45)67
                // a = 12
                // b = 3
                // c = 45
                // d = 67
                
                string a = (i == 0) ? "" : exp.substr(0, i);
                string b = exp.substr(i, plus - i);
                string c = exp.substr(plus + 1, j - plus);
                string d = (j == N - 1) ? "" : exp.substr(j+1, N - j + 1);
                
                string newExp = a + "(" + b + "+" + c + ")" + d;

                int x = (a == "") ? 1 : stoi(a);
                int y = stoi(b) + stoi(c);
                int z = (d == "") ? 1 : stoi(d);

                if (maxVal > x*y*z)
                {
                    maxVal =  x*y*z;
                    res = newExp;
                }
            }
        }

        return res;
    }
};