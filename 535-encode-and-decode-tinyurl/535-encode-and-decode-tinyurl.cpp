class Solution
{
    public:
    unordered_map<string, string> s_to_l;
    unordered_map<string, string> l_to_s;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {  
        if (l_to_s.count(longUrl))
            return "http://tinyurl/" + l_to_s[longUrl];
        
        // generate a hash until we find a non-colliding value.
        string encodedHash = generateEncodedHash(longUrl);        
        while(s_to_l.find(encodedHash) != s_to_l.end())
        {
            encodedHash = generateEncodedHash(longUrl);
        }
        
        string shortUrl = "http://tinyurl/" + encodedHash;
        s_to_l[shortUrl] = longUrl;
        l_to_s[longUrl] = encodedHash;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return s_to_l[shortUrl];
    }
    
    private:
    string generateEncodedHash(string s)
    {
        char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        int hash_length = 8;
        string result;
        result.resize(hash_length);
        
        std::mt19937 generator;
        std::sample(std::begin(charset),        // std::sample selects 'n' elements from sequence such that
                    std::end(charset),          // each possible sample has equal probability of appearance, 
                    std::begin(result),         // and writes those selected elements into the output iterator out. 
                    std::intptr_t(hash_length), // Random numbers are generated using the random number generator g.
                    std::forward<std::mt19937>(generator));
        
        return result;
    }
    
};