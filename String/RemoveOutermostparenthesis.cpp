// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

// Example 1:

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation:
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
// Example 2:

// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation:
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        stack<char> st;
        vector<int> remove;

        int i = 0, start = 0, len = s.size();

        while (i < len)
        {

            if (s[i] == '(')
            {
                st.push('(');
            }
            else
            {
                st.pop();

                if (st.empty())
                {
                    remove.push_back(start);
                    remove.push_back(i);
                    start = i + 1;
                }
            }
            i++;
        }

        string ans;
        int rv_ind = 0;
        for (int i = 0; i < len; i++)
        {

            if (i == remove[rv_ind])
            {
                rv_ind++;
                continue;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};