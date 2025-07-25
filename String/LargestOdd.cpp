// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""

class Solution
{
public:
    string largestOddNumber(string num)
    {

        int len = num.size();
        int i = len - 1, end = -1;
        while (i >= 0)
        {

            if ((num[i] - 48) % 2 == 1)
            {
                // cout<<(num[i]-48)%2;
                end = i;
                break;
            }
            i--;
        }

        if (end == -1)
            return "";

        return num.substr(0, end + 1);
    }
};