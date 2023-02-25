#include <lt_help/lt.h>

class Solution {
public:
    int divide(int dividend, int divisor) { 
        return (int)_divide(dividend, divisor);
    }

    long _divide(long dividend, long divisor) {
        if( divisor == 1 )           return dividend;
        if( dividend == -2147483648 && divisor == -1) return 2147483647;
        if( dividend < 0)            return -_divide(-dividend, divisor);
        if( divisor < 0)             return -_divide(dividend, -divisor);
        if( dividend < divisor )     return 0;
        if( dividend == divisor )    return 1;        

        int dividend_len = _lenOf(dividend);
        int divisor_len  = _lenOf(divisor);
        int diff_len = dividend_len - divisor_len;
        if( diff_len == 0)
            return 1;

        long dividend2 = dividend, dividend3 = 0;
        int bit = 1, move = 0;

        for(int i = diff_len-1; i > 0; --i)
        {   dividend2 = dividend2 >> 1;
            dividend3 += dividend & bit;
            bit = bit << 1;
            ++move;
        }

        if( (dividend2 >> 1) >= divisor )
        {   dividend2 = dividend2 >> 1;
            dividend3 += dividend & bit;
            bit = bit << 1;
            ++move;
        }
        else
            ++diff_len;
        
        //cout << "dividend2="<<dividend2<<", divisor="<<divisor<<", bit=" << bit << ", move=" << move<< endl;
        dividend2 -= divisor;
        
        if( dividend2 > 0)
        {   for(int i = 0;i < move; ++i)
                dividend2 = dividend2 << 1;
        }

        dividend2 += dividend3;
        
        return bit + _divide(dividend2, divisor);
    }
    
    int _lenOf(long n)
    {   int len = 0;
        for(; n > 0; n = n >> 1)
            len++;
        return len;
    }
};


void test(int dividend, int divisor)
{
    cout << "input: dividend=" << dividend << ", divisor=" << divisor;
    int r = Solution().divide(dividend, divisor);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(10, 3);
}


// Result 
//
// 2022-12-06: Runtime 8ms 14.9% Memory 5.8MB 91.76%, https://leetcode.com/problems/divide-two-integers/submissions/855340706/
// 2023-02-16: Runtime 0ms 100% Memory 6MB 9.77%, https://leetcode.com/problems/divide-two-integers/submissions/899196980/


