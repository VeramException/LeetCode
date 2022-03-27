class Solution 
{
    public:
 string removeDuplicates(string s) {
        int n=s.size();
        stack<char> st;
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i])
            {
                st.pop();
                continue;
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};