// Sum of Beauty of All Substrings

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:

// Input: s = "aabcbaa"
// Output: 17

class Solution
{
public:
    int maxfreq(vector<int> &freq)
    {
        int maxi = INT_MIN;

        for (int i = 0; i < freq.size(); i++)
        {
            maxi = max(maxi, freq[i]);
        }
        return maxi;
    }
    int minfreq(vector<int> &freq)
    {
        int mini = INT_MAX;

        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                mini = min(mini, freq[i]);
            }
        }
        return mini;
    }
    int beautySum(string s)
    {

        int sumOfbeauty = 0;
        for (int i = 0; i < s.size(); i++)
        {

            vector<int> freq(26, 0);
            for (int j = i; j < s.size(); j++)
            {

                freq[s[j] - 'a']++;
                int beauty = maxfreq(freq) - minfreq(freq);

                sumOfbeauty += beauty;
            }
        }

        return sumOfbeauty;
    }
};