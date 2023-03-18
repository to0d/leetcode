#include <lt_help/lt.h>

class Solution {
public:
    int myAtoi(string str) {
        int pos = 0, len = str.length();
        while( pos < len && str.at(pos) == ' ') // skip white space
            ++pos;
        char c, sign = '+';
        if( pos < len && ((c = str.at(pos)) == '+' || c == '-'))
        {   sign = c;
            ++pos;
        }
        long long res = 0, n = 0, over = sign == '+' ? 2147483647 : 2147483648; // INT_MIN (-2147483648), INT_MAX (2147483647) 
        for(; pos < len && isdigit(c = str.at(pos)); ++pos)
        {   res = res*10 + (c - '0');
            ++n;
            if( res > over )
                return sign == '+' ? INT_MAX : INT_MIN;
        }
        if(n == 0)
             return 0;
        return sign == '+' ? res : -res;
    }
};



void test(string str)
{
    cout << "input: " << str;
    int r = Solution().myAtoi(str);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{  
    test("12345678");
    test("  0000000000012345678");
}

// Result 
//
// 2023-02-09: Runtime 4ms 61.65% Memory 7.1MB 19.55%, https://leetcode.com/problems/string-to-integer-atoi/submissions/894765461/
// 2023-03-15: Runtime 4ms 59.10% Memory 6.9MB 93.3%, https://leetcode.com/problems/string-to-integer-atoi/submissions/915706679/


