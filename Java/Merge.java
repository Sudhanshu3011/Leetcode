package Java;

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

//Applied the logic of the merge sort 
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] merged = new int[m + n];
        int index1 = 0, index2 = 0, i = 0;

     
        while (index1 < m && index2 < n) {
            if (nums1[index1] < nums2[index2]) {
                merged[i] = nums1[index1];
                index1++;
            } else {
                merged[i] = nums2[index2];
                index2++;
            }
            i++;
        }

      
        while (index1 < m) {
            merged[i] = nums1[index1];
            index1++;
            i++;
        }
        while (index2 < n) {
            merged[i] = nums2[index2];
            index2++;
            i++;
        }

     
        for (int j = 0; j < m + n; j++) {
            nums1[j] = merged[j];
        }
    }
}

