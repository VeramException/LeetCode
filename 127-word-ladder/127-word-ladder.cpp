class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (beginWord == endWord)
            return 0;

        /************* STEP - 1 ***********/
        /**** Build a intermediate map ****/
        /**********************************/

        unordered_map <string, vector<string>> umap;
        for (int i = 0; i < beginWord.size(); i++)
        {
            // Example:
            // beginWord = hit
            // umap = {"*it", {"hit"}
            //        {"h*t", {"hit"}
            //        {"hi*", {"hit"}}

            string str = beginWord.substr(0, i) + "*" + beginWord.substr(i+1);
            umap[str].push_back(beginWord);
        }

        // just how we added intermediate and original word mapping for beginWord,
        // do the same for all words in the wordList.
        for (auto iter = wordList.begin(); iter != wordList.end(); iter++)
        {
            string word = *iter;
            for (int j = 0; j < word.size(); j++)
            {
                string str = word.substr(0, j) + "*" + word.substr(j + 1);
                umap[str].push_back(word);
            }
        }

        /************************* STEP - 2 ********************/
        /**** Apply BFS technique (queue push and retreive) ****/
        /*******************************************************/

        // Intermediate word-map is ready now. Now, just apply BFS.
        queue <pair<string, int>> q;  // queue of (word and distance)
        unordered_set<string> visited;

        // initialize the queue with beginWord.
        q.push(make_pair(beginWord, 1));
        visited.insert(beginWord);

        while (!q.empty())
        {
            pair<string, int> p = q.front(); q.pop();

            string word = p.first;
            int distance = p.second;

            // if target word is found, return distance
            if (word == endWord)
                return distance;

            for (int i = 0; i < word.size(); i++)
            {
                string str = word.substr(0, i) + "*" + word.substr(i + 1);

                vector<string> vect = umap[str];
                for (int j = 0; j < vect.size(); j++)
                {
                    if (visited.count(vect[j]) == 0 )
                    {
                        visited.insert(vect[j]);
                        
                        // I think we can just return here, if target word is found
                        if (vect[j] == endWord)
                            return distance+1;
                        
                        q.push(make_pair(vect[j], distance+1));
                    }
                }
            }
        }

        // if we don't find endWord
        return 0;
    }
};