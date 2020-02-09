/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following 
requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 
candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 
candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
*/

//solution
class Solution 
{
    public:
    int candy(vector<int>& ratings) 
    {
        int result=0,n=ratings.size(),dp[n];
        for(int i=0;i<n;i++) dp[i]=1;   
        for(int i=0;i<n-1;i++) if(ratings[i]<ratings[i+1]) dp[i+1] = dp[i]+1;   
        for(int i=n-1;i>0;i--) if(ratings[i-1]>ratings[i]&&dp[i-1]<dp[i]+1) dp[i-1]=dp[i]+1;
        for(int i=0;i<n;i++) result+=dp[i];   
        return result;
    }
};