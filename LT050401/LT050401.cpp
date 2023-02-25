#include <lt_help/lt.h>

class Solution {
public:
    string convertToBase7(int num) {
        if( num == 0)
            return "0";

        static char buf[128];
        int pos = sizeof(buf);
        bool neg = false;
        if( num < 0 )
        {   neg = true;
            num = -num;
        }

        for(; num > 0; num /= 7)
            buf[--pos] = '0' + num%7;

        if(neg)
            buf[--pos] = '-';

        return string(buf+pos, sizeof(buf) - pos);        
    }
};



void test(int num)
{
    cout << "input: " << num << "; output: "; 
    string r = Solution().convertToBase7(num);
    cout << r << ";" << endl;
}

int main(void)
{
    test(0);
    test(100);
}

// Result 
//
// 2023-02-24: Runtime 0ms 100% Memory 6MB 13.86%, https://leetcode.com/problems/base-7/submissions/904148966/
