package Java;
// The problem is to identify two specific numbers from an array of n integers where each integer from 1 to n appears 
// exactly once except for one number that appears twice (A) and one number that is missing (B). The goal is to return 
// these numbers [A, B] in linear time complexity and without using extra memory.

//Brute force
public class Missing {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int[] repeatedNumber(final int[] A) {
        
        boolean[] newArr = new boolean[A.length + 1]; 
        int[] Ans = new int[2];
        
        int duplicate = -1;
        int missing = -1;

        
        for (int i = 0; i < A.length; i++) {
            if (newArr[A[i]] == true) {
                duplicate = A[i];
            } else {
                newArr[A[i]] = true;
            }
        }
        
        
        for (int i = 1; i < newArr.length; i++) { 
            if (newArr[i] == false) {
                missing = i;
                break;
            }
        }
        
        Ans[0] = duplicate;
        Ans[1] = missing;

        return Ans;
    }
}


//can be solved with making the addition of the element and the square of the element and then finding two equation to solve it



