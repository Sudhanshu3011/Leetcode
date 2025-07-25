// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int el, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                el = nums[i];
            }
            if (nums[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int ct = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el)
            {
                ct++;
            }
        }
        if (ct > (nums.size() / 2))
        {
            return el;
        }
        else
        {
            return -1;
        }
    }
};