// Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

class Solution
{
public:
    void validparenthesis(vector<string> &ans, string path, int open, int close, int target)
    {
        if ((open == target) && (close == target))
        {
            ans.push_back(path);
            return;
        }
        if (close > open)
        {
            return;
        }

        if (open + 1 <= target)
        {
            path.push_back('(');
            validparenthesis(ans, path, open + 1, close, target);
            path.pop_back();
        }
        if (close + 1 <= target)
        {
            path.push_back(')');
            validparenthesis(ans, path, open, close + 1, target);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string path = "";

        validparenthesis(ans, path, 0, 0, n);
        return ans;
    }
};