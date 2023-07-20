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

        char buf[20] = {0}; int len = 0;

        for(int lvl = 1000, deep = 3; num > 0; num %= lvl, lvl /= 10, --deep)
        {   char c1 = RomanNum[deep][0], c5 = RomanNum[deep][1];
            int n = num / lvl;
            switch( n )
            {   case 3:  buf[len++] = c1; 
                case 2:  buf[len++] = c1; 
                case 1:  buf[len++] = c1;
                case 0:  break;
                case 4:  buf[len++] = c1; 
                case 5:  buf[len++] = c5; break;
                case 6:  buf[len++] = c5; buf[len++] = c1; break;
                case 7:  buf[len++] = c5; buf[len++] = c1; buf[len++] = c1; break;
                case 8:  buf[len++] = c5; buf[len++] = c1; buf[len++] = c1; buf[len++] = c1; break;
                case 9:  buf[len++] = c1; buf[len++] = RomanNum[deep+1][0]; break;
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
// 2023-07-20: Runtime 0 ms 100.00% Memory 5.8 MB 77.58%, https://leetcode.cn/submissions/detail/448654963/


