/*
In an infinite binary tree where every node has two children, 
the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), 
the labelling is left to right, while in the even numbered rows 
(second, fourth, sixth,...), the labelling is right to left.



Given the label of a node in this tree, return the labels in the path from 
the root of the tree to the node with that label.

Example 1:

Input: label = 14
Output: [1,3,4,14]

Example 2:

Input: label = 26
Output: [1,2,6,10,26]
 
Constraints:

1 <= label <= 10^6
*/

//solution
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int height = log2(label);
        res.push_back(label);
        while(height > 0){
            int left = pow(2, height - 1);
            int right = pow(2,height) - 1;
            label = left + (right - label/2);
            res.push_back(label);
            height--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};