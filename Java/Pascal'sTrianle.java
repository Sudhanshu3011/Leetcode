// Problem Description
// Given an integer numRows, return the first numRows of Pascal's Triangle.

// Pascal's Triangle Formation
// In Pascal's Triangle:

// The first row is always [1].
// Each subsequent row is constructed by summing adjacent elements from the row directly above it.
// The first and last elements of each row are always 1.
// Example Formation
// Example 1: numRows = 5
// Let's construct the first 5 rows of Pascal's Triangle:

// Row 1: [1]

// This is the starting row.
// Row 2: [1, 1]

// Start and end with 1.
// No elements in between to sum up.
// Row 3: [1, 2, 1]

// Start and end with 1.
// Middle element is the sum of the two numbers directly above it: 1 + 1 = 2.
// Row 4: [1, 3, 3, 1]

// Start and end with 1.
// Middle elements are the sums of the pairs of numbers directly above them:
// 1 + 2 = 3
// 2 + 1 = 3
// Row 5: [1, 4, 6, 4, 1]

// Start and end with 1.
// Middle elements are the sums of the pairs of numbers directly above them:
// 1 + 3 = 4
// 3 + 3 = 6
// 3 + 1 = 4
//implementation 
public class Solution {

    public int combination(int n, int k) {
       
       if (k > n - k) {
           k = n - k;
       }
       int result = 1;
       for (int i = 0; i < k; i++) {
           result *= (n - i);
           result /= (i + 1);
       }
       return result;
    }

   public List<List<Integer>> generate(int numRows) {

       List<List<Integer>> pascalTriangle = new ArrayList<>();

       for(int i=0;i<numRows;i++)
       {

           List<Integer> Rows = new ArrayList<>();
           for(int j=0;j<=i;j++)
           {
            int elementOfTraingle=combination(i,j);

                Rows.add(elementOfTraingle);
                           
           }

           pascalTriangle.add(Rows);

       }

   

return pascalTriangle;
}

}
