class Solution
{
public:
    int largestInteger(int num)
    {
        priority_queue<char> even;
        priority_queue<char> odd;
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i]-'0') % 2 == 0)
                even.push(s[i]);
            else
                odd.push(s[i]);
        }

        string res = s;
        for (int i = 0; i < res.size(); i++)
        {
            if ((s[i] - '0') % 2 == 0)
                s[i] = even.top(), even.pop();
            else
                s[i] = odd.top(), odd.pop();
        }

        int maxVal;
        maxVal = stoi(s);
        return maxVal;
    }
};