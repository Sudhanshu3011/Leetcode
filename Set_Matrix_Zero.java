// Problem Description
// You are given a 2D integer matrix matrix with dimensions m x n. Your task is to modify the matrix in place such that if any element in the matrix is zero, you set all the elements in the same row and column as that zero to zero.

// Constraints
// m == matrix.length (the number of rows in the matrix)
// n == matrix[0].length (the number of columns in the matrix)
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1 (each element in the matrix can be as small as -231 and as large as 231 - 1)
//implementatt=ion
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        
        int[][] checkZero = new int[m][n];

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    checkZero[i][j] = 1;
                }
            }
        }

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (checkZero[i][j] == 1) {
                    
                    for (int k = 0; k < n; k++) {
                        matrix[i][k] = 0;
                    }
                   
                    for (int k = 0; k < m; k++) {
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
}
