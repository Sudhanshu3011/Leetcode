package Java;
// You are asked to implement a function pow(x, n) which calculates 
// x raised to the power of 𝑛
// This function should handle both positive and negative integer exponents efficiently.

// Examples
// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000

// Approach
// To efficiently calculate you can use the method of exponentiation by squaring. This method allows the power function to be computed in 
// O(logn) time complexity, which is much more efficient than the naive approach that takes O(n).


class Solution {
    public double myPow(double x, int n) {

        double ans = 1.0;
        long nn = n;
         if(nn<0) nn = -1 * nn;

         while(nn > 0)
        {
            if(nn % 2 == 1) 
            {
            ans = ans * x;
            nn = nn - 1;
            }
         
             else 
             {
             x = x * x;
             nn = nn / 2;
         
             }
        }
         
         if(n<0) ans=(double)(1.0) /(double)(ans);
         return ans;
                 
    }
}
