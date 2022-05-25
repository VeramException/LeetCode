#define ll long long
#define vb vector<bool>
#define vi vector<int>
#define vl vector<long long>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define f(i,s,e) for(int i = s; i < e; i++)
#define b(i,s,e) for(int i = s; i >= e; i--)

class Solution {
public:
    int maxEnvelopes(vvi& envelopes) {
        auto comp = [](vi& a,vi& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(envelopes.begin(),envelopes.end(),comp);
        vi lis;

        for(auto &e:envelopes) {
            auto lb = lower_bound(lis.begin(),lis.end(),e[1]);
            if(lb == lis.end()) lis.push_back(e[1]);
            else *lb = e[1];
        }

        return lis.size();
    }
};