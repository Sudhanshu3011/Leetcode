// Given an array of characters chars, compress it using the following algorithm :

//     Begin with an empty string s.For each group of consecutive repeating characters in chars :

//     If the group's length is 1, append the character to s. Otherwise,
//     append the character followed by the group's length. The compressed string s should not be returned separately, but instead, be stored in the input character array chars.Note that group lengths that are 10 or longer will be split into multiple characters in chars.

//                                                                                                                                                                                                                      After you are done modifying the input array,
//     return the new length of the array.

//            You must write an algorithm that uses only constant extra space.

//            Example 1 :

//     Input : chars = [ "a", "a", "b", "b", "c", "c", "c" ] Output : Return 6,
//             and the first 6 characters of the input array should be : [ "a", "2", "b", "2", "c", "3" ] Explanation : The groups are "aa", "bb", and "ccc".This compresses to "a2b2c3".Example 2 :

//     Input : chars = [ "a" ] Output : Return 1,
//             and the first character of the input array should be : [ "a" ] Explanation : The only group is "a", which remains uncompressed since it's a single character.

class Solution
{
public:
    int compress(vector<char> &chars)
    {

        string ans = "";
        int left = 0, right = 0, n = chars.size();

        while (right != n && left != n)
        {

            while (right < n - 1 && chars[left] == chars[right + 1])
            {

                right++;
            }

            if (right - left + 1 > 1)
            {
                ans.push_back(chars[left]);
                // here i need to make the integer into the sting and characterwise put it into the stack
                for (char c : to_string(right - left + 1))
                {
                    ans.push_back(c);
                }
            }
            else
                ans.push_back(chars[left]);

            right++;
            left = right;
        }

        // cout<<ans;

        for (int i = 0; i < ans.size(); i++)
        {
            chars[i] = ans[i];
        }

        return ans.size();
    }
};