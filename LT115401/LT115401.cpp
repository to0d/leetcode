#include <lt_help/lt.h>

class Solution {
public:
    int dayOfYear(string date) {
        int year  = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day   = atoi(date.substr(8, 2).c_str());
        int* days = isLeapYear(year) ? days2 : days1;
        int  dth   = 0;
        for(int i = 1;i < month; ++i)
            dth += *(days+i-1);
        dth += day;
        return dth;
    }

    static int isLeapYear(int year) {   
        return year%100 != 0 ? year%4 == 0 : year%400 == 0;
    }

    static int days1[12];
    static int days2[12];
};

int Solution::days1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Solution::days2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};



void test(string date)
{
    cout << "input: " << date;
    int r = Solution().dayOfYear(date);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("2019-01-09");
    test("1900-05-02");
}


// Result 
//
// 2022-12-11: Runtime 49ms 15.88% Memory 5.8MB 96.38%, https://leetcode.com/problems/day-of-the-year/submissions/858023485/
// 2023-02-24: Runtime 27ms 50.14% Memory 6MB 52.32%, https://leetcode.com/problems/day-of-the-year/submissions/904202618/



