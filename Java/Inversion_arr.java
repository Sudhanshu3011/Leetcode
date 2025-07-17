package Java;
// The problem of finding the number of inversions in an array is a common problem in computer science, especially in the context of sorting algorithms.

// Problem Description
// Objective: Count the number of inversions in an array.

// Definition: An inversion in an array is a pair of indices (i, j) such that i < j and arr[i] > arr[j]. Essentially, it measures how out-of-order the array is compared to a sorted array.

// Input: An array of integers arr of length n.

// Output: The number of inversions in the array.

// Example
// Input: [2, 3, 8, 6, 1]

// Output: 5

// Explanation:

// The inversions are:
// (2, 1) because 2 > 1 and 2 comes before 1
// (3, 1) because 3 > 1 and 3 comes before 1
// (8, 6) because 8 > 6 and 8 comes before 6
// (8, 1) because 8 > 1 and 8 comes before 1
// (6, 1) because 6 > 1 and 6 comes before 1
// Total number of inversions: 5


//brute method 
import java.util.* ;
import java.io.*; 
public class Solution {
    public static long getInversions(long arr[], int n) {
        // Write your code here.
        long count=0;

        for(int i=0;i<arr.length;i++)
        {
            for(int j=i+1;j<arr.length;j++)
            {
                if(arr[j]<arr[i])
                {
                    count++;
                }
            }
        }
        return count;
    }
}


//optimal solution with the merge and sort logic implementation
//use the count algorithm for the udation of the inversion in the array which are possible

public class MergeSort {

    // Main function to sort an array using merge sort
    public static long mergeSort(long[] arr, int left, int right) {
        long count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

           // here the count is added in each of the call of the made by the function 
            count += mergeSort(arr, left, mid);
            count += mergeSort(arr, mid + 1, right);

            
            count += merge(arr, left, mid, right);
        }
        return count;
    }

    // Function to merge two sorted subarrays
    private static long merge(long[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays to hold the data
        long[] leftArr = new long[n1];
        long[] rightArr = new long[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        long count = 0;

        // Merge the temporary arrays back into the original array
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                count += (n1 - i); // Count inversions
            }
        }

        // Copy any remaining elements of leftArr
        while (i < n1) {
            arr[k++] = leftArr[i++];
        }

        // Copy any remaining elements of rightArr
        while (j < n2) {
            arr[k++] = rightArr[j++];
        }

        return count;
    }
}
