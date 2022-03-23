class Solution
{
    public:
    string addBoldTag(string s, vector<string>& words)
    {   
        // Step-1: Create Intervals
        set<pair<int, int>> rawIntervals;
        for (string word: words)
        {
            int si = 0; // start index
            while (s.find(word, si) != string::npos)
            {
                si = s.find(word, si);
                rawIntervals.insert({si, si+word.size()-1});
                si++;
            }
        }
        
        // Step-2: Merge Oerlapping Intervals
        vector<pair<int, int>> intervals;
        for (auto item: rawIntervals)
        {
            if(intervals.size()>0 && item.first <= intervals.back().second + 1)
                intervals.back().second = max(intervals.back().second, item.second);
            else
                intervals.push_back(item);
        }
        
        // Step-3: Insert <b></b> at Intervals
        string res(s);
        for (int i=intervals.size()-1; i>=0; i--)
        {
            res.insert(intervals[i].second+1, "</b>");
            res.insert(intervals[i].first, "<b>");
        }
        return res;
    }
};