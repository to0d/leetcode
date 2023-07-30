#include <lt_help/lt.h>

class Solution {
public:
    bool isHappy(int n) {
        int d = n;
        int HappyValue[1000] = {0};         // INT_MAX: 2147483647
        while( d != 1 )                     //      max possible value 999999999
        {   int sum = 0;                    //      9*9*9 < 1000
            for (; d > 0; d /=10 )
            {   int a = d%10;
                sum += a*a;
            }
            if( HappyValue[sum]++ != 0 )
                break;
            d = sum;
        }
        return d == 1;
    }
};



void test(long n)
{
    cout << "input: " << n << "; output: ";
    bool r = Solution().isHappy(n);
    cout << r << ";" << endl;
}

int main(void)
{
    test(19); 
    test(1999999999); 
}

// Result 
//
// 2022-11-21: Runtime 4ms 39.37% Memory 6.5MB 6.58%, https://leetcode.com/problems/happy-number/submissions/846973268/
// 2023-02-22: Runtime 4ms 38.78% Memory 6.7MB 6.74%, https://leetcode.com/problems/happy-number/submissions/902628893/
// 2023-07-30: Runtime 0ms 100% Memory 5.73MB 83.54%, https://leetcode.cn/problems/happy-number/submissions/451563367/


