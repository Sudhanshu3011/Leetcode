// 560. Subarray Sum Equals K
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int prefixsum = 0, count = 0, remove;
        map<int, int> mpp;
        int n = nums.size();
        mpp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            prefixsum += nums[i];
            remove = prefixsum - k;
            if (mpp.find(remove) != mpp.end())
            {
                count += mpp[remove];
            }
            mpp[prefixsum]++;
        }

        return count;
    }
};