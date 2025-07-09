// Sort Characters By Frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.\

class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();

        priority_queue<pair<int, char>> pq;

        map<char, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[s[i]]++;
        }

        for (auto &itr : mpp)
        {

            char ch = itr.first;
            int freq = itr.second;

            pq.push({freq, ch});
        }

        string str;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int freq = it.first;
            char ch = it.second;

            str += string(freq, ch);
        }

        return str;
    }
};