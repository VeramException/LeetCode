class Solution
{
public:

    // Find words differing by a single character with word
    vector<string> addWord(string word, unordered_set<string>& dict)
    {
        vector<string> res;

        // Find next word in dict by changing
        // each element from 'a' to 'z'
        for (int i = 0; i < word.size(); i++)
        {
            char s = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == s) continue;
                word[i] = c;
                if (dict.count(word))
                    res.push_back(word);
            }
            word[i] = s;
        }
        return res;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> resultPaths;
        unordered_set<string> visitedWords;
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        bool shortestPathFound = false;
        
        queue<vector<string>> q;
        q.push({ beginWord });

        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++)
            {
                vector<string> curr_level = q.front(); q.pop();
                vector<string> newadd = addWord(curr_level.back(), dictionary);

                // Add words to the path.
                for (int j = 0; j < newadd.size(); j++)
                {
                    vector<string> newline(curr_level.begin(), curr_level.end());
                    newline.push_back(newadd[j]);

                    // Found the target
                    if (newadd[j] == endWord)
                    {
                        shortestPathFound = true;
                        resultPaths.push_back(newline);
                    }

                    visitedWords.insert(newadd[j]);
                    q.push(newline);
                }
            }

            if (shortestPathFound)
                break;

            // Erase all visited words.
            for (auto it : visitedWords)
                dictionary.erase(it);

            visitedWords.clear();
        }

        return resultPaths;
    }
};