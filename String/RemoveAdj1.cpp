// Remove All Adjacent Duplicates In String

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
// Example 2:

// Input: s = "azxxzy"
// Output: "ay"

class Solution
{
public:
    string removeDuplicates(string s)
    {

        string ans;
        for (char c : s)
        {

            if (!ans.empty() && ans.back() == c)
            {
                ans.pop_back();
            }
            else
            {

                ans.push_back(c);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int adj(string s) {

//         char pt1 = s[0];
//         char pt2;
//         for (int i = 1; i < s.size(); i++) {

//             pt2 = s[i];
//             if (pt1 == pt2)
//                 return i - 1;

//             pt1 = pt2;
//         }

//         return -1;
//     }
//     string rmvdupli(string& s) {
//         if(s.empty())return "";
//         if (adj(s) == -1) {
//             return s;
//         }

//         int ind = adj(s);

//         s.erase(ind,2);

//         return rmvdupli(s);
//     }

//     string removeDuplicates(string s) {
//         return rmvdupli(s);
//     }
// };