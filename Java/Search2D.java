package Java;
// You are given an m×n integer matrix with the following properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if the target is in the matrix or false otherwise.

// Your solution must have a time complexity of 
// O(log(m⋅n)).


//time complexity is of O(m+n)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

        int row=-1;
        
        for(int i=0; i<matrix.length;i++)
        {
            if(matrix[i][matrix[0].length-1]>=target)
            {
                row=i;
                break;
            }
        }
        if(row==-1)return false;

        for(int j=0;j<matrix[0].length;j++)
        {
            if(matrix[row][j]==target)
            {
                return true;
            }
        }

        return false;
    }
}



//time complexity of the O(log(m+n))
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }

        int m = matrix.length;
        int n = matrix[0].length;

        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int row = mid / n; 
            int col = mid % n; 

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
}
