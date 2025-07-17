package Java;
// The task is to identify the majority element in a given array. The majority element is defined as the element that appears more than half the time in the array (i.e., more than ⌊n / 2⌋ times, where n is the size of the array). The problem guarantees that there is always a majority element present in the array.

// Examples:

// Input: nums = [3,2,3]
// Output: 3

// Explanation: In the array [3, 2, 3], the number 3 appears twice, which is more than half the length of the array (⌊3 / 2⌋ = 1.5, rounded down to 1). Hence, 3 is the majority element.

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Explanation: In the array [2, 2, 1, 1, 1, 2, 2], the number 2 appears four times, which is more than half the length of the array (⌊7 / 2⌋ = 3.5, rounded down to 3). Therefore, 2 is the majority element.

// Explanation:
// The intuition behind the Boyer-Moore Voting Algorithm is that it pairs off different elements against each other. Since the majority element appears more than half the time, it will eventually outnumber the others and be left as the candidate.

// Example:
// Consider the array nums = [2, 2, 1, 1, 1, 2, 2].

// Initialization:

// candidate = None
// count = 0
// Iteration:

// Element 2:

// count = 0 → candidate = 2, count = 1
// Element 2:

// candidate = 2 → count = 2
// Element 1:

// candidate != 1 → count = 1
// Element 1:

// candidate != 1 → count = 0
// Element 1:

// count = 0 → candidate = 1, count = 1
// Element 2:

// candidate != 2 → count = 0
// Element 2:

// count = 0 → candidate = 2, count = 1
// Element 2:

// candidate = 2 → count = 2


class Solution {
    public int majorityElement(int[] nums) {
        
        int count=0;
        int element=0;

        for(int i=0;i<nums.length;i++)
        {
            if(count==0)
            {
                count++;
                element=nums[i];
            }
            else if(nums[i]==element)
            {
                count++;
            }
            else{
                count--;
            }
        }
        int check=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==element)
            {
                check++;
            }
        }
        if(check>nums.length/2)
        {
            return element;
        }
        else{
            return -1;
        }
    }
}


//Hash Mapping can also be implemented