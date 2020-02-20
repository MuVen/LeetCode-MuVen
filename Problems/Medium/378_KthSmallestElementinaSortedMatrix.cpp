/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order,
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
class Solution {
    typedef pair<int, pair<int,int>> vrc;
    priority_queue<vrc, vector<vrc>, greater<vrc>> minHeap;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
            minHeap.push({matrix[i][0],{i, 0}});
        //push value, row, coloumn value to min heap and pull out kths small value.
        int res = 0;
        while(k--){
            auto svalue = minHeap.top();minHeap.pop();
            res = svalue.first;
            auto spair = svalue.second;
            if(spair.second < col - 1)
                minHeap.push({matrix[spair.first][spair.second+1],{spair.first, spair.second+1}});
        }
        return res;
    }
};