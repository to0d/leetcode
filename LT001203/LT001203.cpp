#include <lt_help/lt.h>

class Solution {
public:
    string intToRoman(int num) {
        if( num >= 4000 || num == 0)
            return "";
        
        static char RomanNum[4][2] = {
            { 'I','V' },    // I: 1,   V: 5
            { 'X','L' },    // X: 10,  L: 50 
            { 'C','D' },    // C: 100, D: 500
            { 'M','-' }     // M: 1000
        };

        int stack[4] = {0};
        int deep = 0;
        for(; num > 0; num /= 10)
            stack[deep++] = num % 10;
        
        static char buf[256] = {0};
        int len = 0;
        for(; deep > 0; --deep )
        {        
            char c1 = RomanNum[deep-1][0];
            char c5 = RomanNum[deep-1][1];

            int val = stack[deep-1];
            switch(val)
            {
            case 0:  break;
            case 1:  buf[len++] = c1; break;
            case 2:  buf[len++] = c1; buf[len++] = c1; break;
            case 3:  buf[len++] = c1; buf[len++] = c1; buf[len++] = c1; break;
            case 4:  buf[len++] = c1; buf[len++] = c5; break;
            case 5:  buf[len++] = c5; break;
            case 6:  buf[len++] = c5; buf[len++] = c1; break;
            case 7:  buf[len++] = c5; buf[len++] = c1; buf[len++] = c1; break;
            case 8:  buf[len++] = c5; buf[len++] = c1; buf[len++] = c1; buf[len++] = c1; break;
            case 9:  buf[len++] = c1; buf[len++] = RomanNum[deep][0]; break;
            }
        }

        return string(buf, len);
    }
};


void test(int num)
{
    cout << "input: " << num;
    string r = Solution().intToRoman(num);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(1994);
}


// Result 
//
// 2023-02-15: Runtime 4ms 85.63% Memory 5.9MB 92.95%, https://leetcode.com/problems/integer-to-roman/submissions/898526547/


