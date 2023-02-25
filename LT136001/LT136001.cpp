#include <lt_help/lt.h>

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return std::abs(dayOfYear(date2) - dayOfYear(date1));
    }
    
    int dayOfYear(string date) {
        int year  = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day   = atoi(date.substr(8, 2).c_str());
        
        int dth = 0;
        for(int y = 1971; y < year; ++y)
            dth += isLeapYear(y)? 366:365;
        
        int* days = isLeapYear(year) ? days2 : days1;
        
        for(int i = 1;i < month; ++i)
            dth += *(days+i-1);
        dth += day;
        
        return dth;
    }
    
    static int isLeapYear(int year){   
        return year%100 != 0 ? year%4 == 0 : year%400 == 0;
    }

    static int days1[12];
    static int days2[12];
};

int Solution::days1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Solution::days2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};




void test(string date1, string date2)
{
    cout << "input: date1=" << date1 << ", date2=" << date2;
    int r = Solution().daysBetweenDates(date1, date2);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("2020-01-15", "2019-12-31");
}


// Result 
//
// 2022-12-13: Runtime 6ms 6.79% Memory 5.9MB 76.47%, https://leetcode.com/problems/number-of-days-between-two-dates/submissions/858933927/
// 2023-02-25: Runtime 0ms 100% Memory 5.9MB 72.61%, https://leetcode.com/problems/number-of-days-between-two-dates/submissions/904211667/




