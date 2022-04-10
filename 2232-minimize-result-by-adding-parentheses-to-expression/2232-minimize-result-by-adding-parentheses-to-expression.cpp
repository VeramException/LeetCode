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

        // 123+4567
        // 12(3+45)67

        for (int i = 0; i < plus; i++)
        {
            for (int j = plus + 1; j < N; j++)
            {
                string a = (i == 0) ? "" : exp.substr(0, i);
                string b = "(" + exp.substr(i, plus - i) + "+" + exp.substr(plus + 1, j - plus) + ")";
                string c = (j == N - 1) ? "" : exp.substr(j+1, N - j + 1);
                string newExp = a + b + c;

                int a_val = (i == 0) ? 1 : stoi(exp.substr(0, i));
                int b_val = stoi(exp.substr(i, plus - i)) + stoi(exp.substr(plus + 1, j - plus));
                int c_val = (j == N - 1) ? 1 : stoi(exp.substr(j + 1, N - j + 1));

                if (maxVal > a_val * b_val * c_val)
                {
                    maxVal =  a_val * b_val * c_val;
                    res = newExp;
                }
            }
        }

        return res;
    }
};