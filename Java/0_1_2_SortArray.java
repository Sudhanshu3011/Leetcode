// Given an array nums containing only 0s, 1s, and 2s, sort the array in ascending order without using extra space for another array (i.e., sorting should be done in-place).

// Example:
// Input: nums = [2, 0, 2, 1, 1, 0]
// Output: [0, 0, 1, 1, 2, 2]
// Approach:
// The Dutch National Flag algorithm is a three-way partitioning algorithm that processes the array in a single pass. The algorithm maintains three regions in the array:

// low: Region containing all 0s.
// mid: Region containing all 1s.
// high: Region containing all 2s.
// The goal is to partition the array into these three regions. The steps are as follows:

// Initialize three pointers: low, mid, and high.

// low and mid start at the beginning of the array.
// high starts at the end of the array.
// Traverse the array with the mid pointer and perform the following actions:

// If nums[mid] is 0, swap nums[mid] with nums[low], and increment both low and mid.
// If nums[mid] is 1, just increment mid.
// If nums[mid] is 2, swap nums[mid] with nums[high], and decrement high.
// Explanation of the Algorithm:

class Solution {
    public void swap(int[] nums, int destination, int source){
        int temp;
        temp=nums[source];
        nums[source]=nums[destination];
        nums[destination]=temp;
    }
    public void sortColors(int[] nums) {
     
     int n=nums.length;
      int low=0,mid=0,high=n-1;       

      while(mid<high){
        for(int i=0;i<n;i++)
        {
            if(nums[mid]==0){
                swap(nums,low,mid);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums,mid,high);
                high--;
            }
        }
      } 
    }
}

//Another approach

class Solution {
   
    public void sortColors(int[] nums) {
     
     int n=nums.length;
      int count0=0;
      int count2=0;
      int count1=0;
      while(mid<high)
      {
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0){
             count0++;
            }
            else if(nums[i]==1){
                count1++;
            }
            else{
                count2++;
            }
        }
      } 

      for(int i=0;i<count0;i++)
      {
        nums[i]=0;
      }
      
      for(int i=count0;i<count0+count1;i++)
      {
        nums[i]=1;
      }
      
      for(int i=count0+count1;i<count0+count1count2;i++)
      {
        nums[i]=2;
      }
    }
}
