/*
Nearly every one have used the Multiplication Table. But could you find out 
the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a 
positive integer k, you need to return the k-th smallest number in this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
Example 2:
Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
*/

//solution
class Solution {
    int lm, ln;
public:
    inline bool enough(int x, int k){
        int count = 0;
        for(int i = 1; i <= lm; i++){
            count = count + min(x/i, ln);
        }
        return count >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        lm = m;
        ln = n;
        int low = 1, high = m * n;
        /*
            1 2 3  4  5  6  7
            2 4 6  8 10 12 14
            3 6 9 12 15 18 21
            
            get the mid, 1 + 21 / 2 = 11.
            find how many elements are less than 11.
            7 elements from 1st row, 5 elements from 2nd row, 
			3 elements from 3rd row.total 15 elements are below element 11.
            
            so 15 elements >= 4 so search for the 4the element 
			in the left half, [low ... mid]
            else [mid+1 ... high]
        
        */
        while(low < high){
            int mid = (low + high)/2;
            if(enough(mid, k) == true){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};