class Solution
{
public:
    bool isMatch(string s, string p)
    {

        for (int i = 0, j = 0; i < s.size(), j <= i; i++, j++)
        {
            if (s[i] != p[j])
            {

                if (p[j] == '*')
                {
                    return true;
                }
                if (p[j] != '.')
                {
                    return false;
                }
            }
        }
        return true;
    }
};