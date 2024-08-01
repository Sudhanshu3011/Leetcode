// The problem is to rotate a given n x n 2D matrix representing an image by 90 degrees clockwise. The rotation must be done in-place, meaning the input matrix should be modified directly without allocating additional space for another matrix.

// Problem Description
// Objective: Rotate an n x n matrix by 90 degrees clockwise.

// Input: An n x n 2D matrix where n is the number of rows (or columns, since the matrix is square). Each element in the matrix represents a pixel in an image.

// Output: The same matrix rotated 90 degrees clockwise.

// Constraints:

// The rotation must be done in-place, so you cannot use extra space for another matrix of the same size.
// The matrix will be modified directly.


//Logically
class Solution {
    
    public void rotate(int[][] matrix) {

        int len=matrix[0].length;
        int[][] submat= new int[len][len];

        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                  submat[i][j]=matrix[i][j];
            }
        }
        
         for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                  matrix[i][j]=submat[len-j-1][i];
            }
        }

        
    }
}

