/*
Given scores of N athletes, find their relative ranks and the people with the 
top three highest scores, who will be awarded medals: "Gold Medal", 
"Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, 
so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

//solution
#define P(VEC) for(auto I : VEC)cout<<I<<" ";cout<<endl;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> ranks(nums.size());
        iota(ranks.begin(), ranks.end(), 0);
        vector<string> res(nums.size());
        /*
            P(nums);
            P(ranks);
            Input: [10,3,8,9,4]
            Ranks before sorting: [0,1,2,3,4]
            Ranks after sorting: [0,3,2,4,1]

            That means that the biggest score is at position 0, first runner up - at the position 3, and so on.
            In the final loop, we "distribute" our awards based on the order of the index array.
        */
        sort(ranks.begin(), ranks.end(), [&](const int& i, const int& j){return nums[i] > nums[j];});
        //P(ranks);
        for (auto i = 0; i < nums.size(); ++i)
            res[ranks[i]] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i + 1);
        return res;
    }
};