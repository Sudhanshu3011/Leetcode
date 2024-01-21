class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> merged;
        int i = 0, j = 0, n;
        double value;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size())
        {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            merged.push_back(nums2[j]);
            j++;
        }

        int size = merged.size();
        n = (size / 2);

        if (size % 2 == 0)
        {

            value = (merged[n] + merged[n - 1]) / 2.0;
        }
        else
        {
            value = merged[n];
        }

        return value;
    }
};