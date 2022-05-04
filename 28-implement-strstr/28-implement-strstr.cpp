class Solution 
{
public:
    
vector<int> BuildLpsArray(string s)
{
	vector<int> lps;

	int i = 0;
	int len = 0;

	lps.push_back(0);
	i = 1;

	while (i < s.size())
	{
		if (s[i] == s[len])
		{
			i++;
			len++;
			lps.push_back(len);
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				len = 0;
				lps.push_back(len);
				i++;
			}
		}
	}
	return lps;
}

int Strstr(string s1, string s2, vector<int> lps)
{
	int i = 0;
	int j = 0;
    
	while (i <= s1.size())
	{
		if (j == s2.size())
		{
			// Found a match
			return (i - s2.size());
		}

		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
	}
    return -1;
}
    
int strStr(string s1, string s2)
{
    vector<int> LpsArray = BuildLpsArray(s2);
    return Strstr(s1, s2, LpsArray);
}
};