// Given an array of integers nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum = 6.

//most optimal Approach
public class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;

        for (int i = 0; i < nums.length; i++) {
            currentSum += nums[i];


            if(currentSum>maxSum){
                maxSum=currentSum;
            }
            if(currentSum<0){
                currentSum=0;
            }
        }

       

        return maxSum;
    }
}


//Finding the max with the subarray
public class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;
        int start,ansStart,ansEnd;

        for (int i = 0; i < nums.length; i++) {
            if(currentSum==0) start=i;
            currentSum += nums[i];


            if(currentSum>maxSum){
                maxSum=currentSum;
                
                ansStart=start;
                ansEndend=i;
            }
            if(currentSum<0){
                currentSum=0;
            }
        }

        for(int i=ansStart;i<=ansEnd;i++){
            System.out.println(nums[i]+" ");
        }

        return maxSum;
    }
}

//Brute Approach
class Solution {
    public int maxSubArray(int[] nums) {
        int maximum = Integer.MIN_VALUE;
        int sum;
        int len = nums.length;

        for (int i = 0; i < len; i++) {
            int sublen = i;
            while (sublen < len) {
                sum = 0;
                for (int j = i; j <= sublen; j++) {
                    sum += nums[j];
                }
                if (sum > maximum) {
                    maximum = sum;
                }
                sublen++;
            }
        }
        return maximum;
    }
}