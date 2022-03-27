class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        int n = queries.size(), m = (intLength + 1) / 2;
        long long s = m > 1 ? stoi(string(m - 1, '9')) : 0, l = stoi(string(m, '9')) - s;
        for (int i = 0; i < n; i++)
        {
            if (queries[i] > l)
                ans.push_back(-1);
            else
            {
                long long h = queries[i] + s;
                string t = to_string(h), r = t;
                reverse(r.begin(), r.end());
                if (intLength % 2)
                    t += r.substr(1);
                else
                    t += r;
                ans.push_back(stoll(t));
            }
        }
        return ans;
    }
};