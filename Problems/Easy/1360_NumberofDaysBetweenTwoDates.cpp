/*
Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.

 

Example 1:

Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1
Example 2:

Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.
*/
static int mdays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Solution {
    struct mdate{
        int day;
        int month;
        int year;
    };
public:
    mdate convertDate(string date){
        mdate m;
        m.year = ((date[0]-'0')*1000)+((date[1]-'0')*100)+((date[2]-'0')*10)+(date[3]-'0');
        m.month = ((date[5]-'0')*10)+(date[6]-'0');
        m.day = ((date[8]-'0')*10)+(date[9]-'0');
        cout<<m.year<<" "<<m.month<<" "<<m.day<<endl;
        return m;
    }
    int ndays(mdate m){
        int days = 0;
        for(int i = 1971; i < m.year; i++){
            if(i % 4 == 0 && (i % 400 == 0 || i % 100 != 0))
                days += 1;
            days += 365;
        }
        
        for(int i = 1; i < m.month; i++){
            days += mdays[i];
        }
        if (m.month > 2 && (m.year % 4 == 0 && (m.year % 400 == 0 || m.year % 100 != 0)))
            days += 1;
            
        days += m.day;
        return days;
    }
    
    int daysBetweenDates(string date1, string date2) {
        mdate d1 = convertDate(date1);
        mdate d2 = convertDate(date2);
        int nd1 = ndays(d1);
        int nd2 = ndays(d2);
        cout<<nd1<<" "<<nd2<<endl;
        return nd1 > nd2 ? nd1-nd2 : nd2-nd1;
    }
};