/*
Given a string date representing a Gregorian calendar date formatted as
 YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
*/

//solution
int days [] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
class Solution {
public:   
    int dayOfYear(string date) {
        int year = 0, month = 0, day = 0;
        for(int i = 0; i < 4; i++){
            year = year*10 + (date[i]-'0');
        }
        for(int i = 5; i < 7; i++){
            month = month*10 + (date[i]-'0');
        }
        for(int i = 8; i < 10; i++){
            day = day*10 + (date[i]-'0');
        }
    
        bool isyleap = (year%4 == 0 && (year%400 == 0 || year%100 != 0));
        int count = 0;
        for(int i = 1; i < month; i++){
            if(i == 2 && isyleap)
                count++;
            count += days[i];
        }
        return count + day;
    }
};