package Java;
// Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to the target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input:
// nums = [2, 7, 11, 15]
// target = 9
// Output: [0, 1]

class Solution {
    public int[] twoSum(int[] nums, int target) {

        int[] arr=new int[2];
        Arrays.sort(nums);
        int left,right;
        left=0;
        right=nums.length-1;

        
        while(left<right){
            
            if(target==nums[left]+nums[right]){
                 arr[0]=left;
                 arr[1]=right;
                 break;
            }
            else if(target<nums[left]+nums[right])right--;
            else left++;
        }
        
        return arr;
    }
}