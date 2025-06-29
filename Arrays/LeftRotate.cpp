// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

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
    void rotate(vector<int> &nums, int k)
    {
        int length = nums.size();
        int n_rotate = k % length;
        reverse(nums, 0, length);
        reverse(nums, 0, n_rotate);
        reverse(nums, n_rotate, length);
    }
};