#include <lt_help/lt.h>



class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1971-01-01 Friday
        int dth = 0;
        for(int y = 1971; y < year; ++y)
            dth += isLeapYear(y)? 366:365;
        int* days = isLeapYear(year) ? days2 : days1;
        for(int i = 1;i < month; ++i)
            dth += *(days+i-1);
        dth += day;
        return weeks[(dth+4)%7];
    }
    static int isLeapYear(int year)
    {   return year%100 != 0 ? year%4 == 0 : year%400 == 0;
    }
    static vector<string> weeks;
    static int days1[12];
    static int days2[12];
};

vector<string> Solution::weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int Solution::days1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Solution::days2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};



void test(int day, int month, int year)
{
    cout << "input: day=" << day << ", month=" << month << ", year=" << year;
    string r = Solution().dayOfTheWeek(day, month, year);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(31, 8, 2019);
}


// Result 
//
// 2022-12-12: Runtime 0ms 100% Memory 6MB 25%, https://leetcode.com/problems/day-of-the-week/submissions/858388279/




