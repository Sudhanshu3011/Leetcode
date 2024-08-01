// You are given an array of integers, nums, containing 
// n+1 integers where each integer is in the range 
// [1,n] inclusive. This means that there are 
// n+1 numbers, but they only range from 1 to n. Because of the pigeonhole principle, there must be at least one repeated number.

// Your task is to find the single repeated number in the array.

// Constraints:

// You must solve the problem without modifying the input array nums.
// You must use only constant extra space.
// The solution must run in linear time, 
// O(n).


class Solution {
    public int findDuplicate(int[] nums) {

        boolean[] newArr = new boolean[nums.length];

        int value = -1;

        for (int i = 0; i < nums.length; i++) {
            if (newArr[nums[i]] == true) {
                value = nums[i];
                break;
            }

            else {
                newArr[nums[i]] = true;
            }
        }

        return value;
    }
}

//Tortoise method
// Floyd's Tortoise and Hare (Cycle Detection) Algorithm
// Floyd's Tortoise and Hare algorithm is a pointer algorithm that uses two pointers to detect cycles in a sequence of values. It is particularly effective in problems involving finding duplicates or cycles without modifying the input data and using constant extra space. Here's a step-by-step explanation:

// Steps to Apply the Algorithm
// Initialization:

// Initialize two pointers, the tortoise and the hare. Both start at the beginning of the array.
// Typically, the tortoise moves one step at a time, while the hare moves two steps at a time.
// Finding the Intersection Point:

// Move the tortoise and hare through the array:
// The tortoise moves one step at a time: tortoise = nums[tortoise].
// The hare moves two steps at a time: hare = nums[nums[hare]].
// Continue this until the tortoise and hare meet. This meeting point confirms the presence of a cycle.
// Finding the Entrance to the Cycle:

// Once a cycle is detected, initialize a new pointer (say ptr1) at the start of the array and another pointer (ptr2) at the meeting point.
// Move both pointers one step at a time until they meet. The meeting point will be the entrance to the cycle, which is the repeated number.


class Solution {
    public int findDuplicate(int[] nums) {
        int slow=nums[0];
        int fast=nums[0];
         
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;

    }
}