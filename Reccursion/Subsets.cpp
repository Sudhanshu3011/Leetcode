// Subsets

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

class Solution
{
public:
    void subseq(vector<vector<int>> &ans, const vector<int> &nums, vector<int> &temp, int ind)
    {
        if (ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        subseq(ans, nums, temp, ind + 1);

        temp.pop_back();
        subseq(ans, nums, temp, ind + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        subseq(ans, nums, temp, 0);
        return ans;
    }
};
