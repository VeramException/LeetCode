class Solution
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& words)
    {
        unordered_map<string, vector<string>> m;
        for (string word: words)
        {
            string t = word;
            sort(t.begin(), t.end());  // this can be improved from O(nLog(n)) to O(n) using counting sort
            m[t].push_back(word);
        }
        
        vector<vector<string>> res;
        for (auto const& [k, v]: m)
            res.push_back(v);
        return res;
    }
    
    /* counting sort 
    string countingSort(string word)
    {
        int count[26] = {0};
        for (char c: word)
            count[c-'a']++;
        
        string sortedWord;
        for (int i=0; i<26; i++)
            sortedWord += string(count[i], i+'a');
        return sortedWord;
    }
    
    */
};

