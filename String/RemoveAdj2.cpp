// Remove All Adjacent Duplicates in String II

// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation:
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {

        string ans;
        vector<int> cnt;

        for (char ch : s)
        {
            if (!ans.empty() && ans.back() == ch)
            {
                cnt.push_back(cnt.back() + 1);
            }
            else
            {
                cnt.push_back(1);
            }

            ans.push_back(ch);

            if (cnt.back() == k)
            {
                ans.erase(ans.end() - k, ans.end());
                cnt.erase(cnt.end() - k, cnt.end());
            }
        }

        return ans;
    }
};