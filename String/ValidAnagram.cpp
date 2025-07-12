// Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        vector<int> s_freq(26, 0), t_freq(26, 0);

        for (int i = 0; i < s.size(); i++)
        {

            s_freq[s[i] - 'a']++;
            t_freq[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (s_freq[i] != t_freq[i])
                return false;
        }
        return true;
    }
};