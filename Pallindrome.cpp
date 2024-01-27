class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0)
        {
            return false;
        }

        long long x1 = x, result = 0;

        while (x != 0)
        {
            result = result * 10 + x % 10;

            x /= 10;
        }

        if (result == x1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};