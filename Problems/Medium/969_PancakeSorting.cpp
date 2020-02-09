/*
Given an array A, we can perform a pancake flip: We choose some positive integer
 k <= A.length, then reverse the order of the first k elements of A. 
 We want to perform zero or more pancake flips (doing them one after another 
 in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A. 
 Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

 

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 

Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
 

Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]
*/

//solution
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int size = A.size();
        vector<int> v;
        while(size){
            //get the maxIndex element;
            int maxIndex = max_element(A.begin(), A.begin() + size) - A.begin();
            //push maxindex element + 1, as you are gonna flip array of that length.
            v.push_back(maxIndex+1);
            //now reverse array from begining till maxIndex+1
            reverse(A.begin(), A.begin() + maxIndex + 1);
            //you got the big number, put it at the end(size)
            v.push_back(size);
            //reverse the array till size.
            reverse(A.begin(), A.begin() + size);
            //size decreases for every iteration.
            size--;
        }
        return v;
    }
};