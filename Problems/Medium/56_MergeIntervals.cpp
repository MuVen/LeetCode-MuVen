/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default 
code definition to get new method signature.
*/

//solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vec) {
        if(vec.size() == 0)
            return vector<vector<int>>{};
        
        sort(vec.begin(), vec.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        auto pit = vec.begin();
        auto cit = pit + 1;

        while (cit != vec.end()){
            vector<int>& pvec = *pit;
            vector<int>& cvec = *cit;
            if (cvec[0] <= pvec[1]){
                //merge;
                if(cvec[1] > pvec[1])
                    pvec[1] = cvec[1];
                cit = vec.erase(cit);
                continue;
            }

            pit = cit;
            cit++;
        }
        
        return vec;
    }
};