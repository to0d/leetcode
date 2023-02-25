#include <lt_help/lt.h>

class Solution {
public:
    string reformatDate(string date) {
        // "20th Oct 2052"
        int dl    = date.size() == 13 ? 2 : 1;
        int day   = std::stoi(date.substr(0, dl));        
        int year  = std::stoi(date.substr(7 + dl, 4));
        
        int month = 0;
        string ms= date.substr(3 + dl, 3);
        for(int i = 0; month == 0 && i < 12; ++i)
            if( ms == months[i] )
                month = i + 1;
        
        static char buf[12];
        int len = sprintf(buf, "%04d-%02d-%02d", year, month, day);
        return string(buf, len);
    }
    
    static string months[12];
};

string Solution::months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


void test(string date)
{
    cout << "input: " << date;
    string r = Solution().reformatDate(date);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("20th Oct 2052");
}


// Result 
//
// 2022-12-13: Runtime 3ms 48.35% Memory 5.8MB 100%, https://leetcode.com/problems/reformat-date/submissions/859220239/
// 2023-02-25: Runtime 0ms 100% Memory 6MB 77.7%, https://leetcode.com/problems/reformat-date/submissions/904216106/



