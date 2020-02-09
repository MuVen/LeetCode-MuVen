/*
Given a non-negative integer, you could swap two digits at most once to get
 the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/
//solution
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int size = str.size();
        // convert int to string
        // if the string is decreasing order return the num as is
        // find the pivot point where number at i is greater than i-1 6548123
        // index at 8 is pivot point.
        int posi = -1;
        for(int i = 1; i < size; i++){
            if(str[i] > str[i-1]){
                posi = i;
                break;
            }
        }
        
        if(posi == -1) return num;
        
        //now find the highest digit which is greater than equal to pivot number.
        int posj = posi;
        for(int i = posj + 1; i < size; i++){
            if(str[i] >= str[posj]){
                posj = i;
            }
        }
        
        cout<<str[posj]<<endl;
        //now traverse from [0, posi] and find the digit which is less than max digit.
        //swap both of these digits and return them.
        for(int i = 0; i < posi; i++){
            if(str[i] < str[posj]){
                swap(str[i], str[posj]);
                break;
            }
        }
        
        return atoi(str.c_str());
    }
};