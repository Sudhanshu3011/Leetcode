// Ninja and his friend are playing a game of subarrays. They have an array ‘NUMS’ of length ‘N’. Ninja’s friend gives him an arbitrary integer ‘K’ and asks him to find the length of the longest subarray in which the sum of elements is equal to ‘K’.

// Ninjas asks for your help to win this game. Find the length of the longest subarray in which the sum of elements is equal to ‘K’.

// If there is no subarray whose sum is ‘K’ then you should return 0.

// Example:
// Input: ‘N’ = 5,  ‘K’ = 4, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]

// Output: 4

// There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.

#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k)
{
    // Write your code here
    map<long long, int> prevSum;
    long long sum = 0;
    int max_length = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];

        if (sum == k)
        {
            max_length = max(max_length, i + 1);
        }

        long long rem = sum - k;

        if (prevSum.find(rem) != prevSum.end())
        {
            int len = i - prevSum[rem];

            max_length = max(max_length, len);
        }
        if (prevSum.find(sum) == prevSum.end())
        {
            prevSum[sum] = i;
        }
    }

    return max_length;
}