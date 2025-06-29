// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        int i = start, temp;
        int j = end - 1;
        while (i < j)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

    bool check(vector<int> &nums)
    {
        int l = nums.size();
        int min = nums[0], index = 0;

        // Find the index of the minimum element
        for (int i = 0; i < l; i++)
        {
            if (min > nums[i])
            {
                min = nums[i];
                index = i;
            }
        }

        // Perform the reversals
        reverse(nums, 0, index);
        reverse(nums, index, l);
        reverse(nums, 0, l);

        // Check if the array is sorted
        for (int i = 0; i < l - 1; i++)
        { // Avoid out-of-bounds access
            if (nums[i + 1] < nums[i])
            {
                return false;
            }
        }

        return true;
    }
};
