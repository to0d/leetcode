#include <lt_help/lt.h>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if( m == 0 ) 
            return 0;

        long r = 0xFFFFFFFF, mm = m, nn = n;
        while( r != 0 && m > 0 && m <=n )
        {   r &= m;
            long bit = mbit(r);
            m &= ~( bit - 1);
            m += bit;
        }

        return (int)r;
    }
    
    long mbit( long x ){
        static long last_x = 1;
        static long last_bit = 1;

        if( x != last_x )
        {   if( x == 0 ) 
                return 0;

            long bit = 1;
            while( bit != 0 && (x | bit) != x )
                bit <<= 1;
            
            last_x = x;
            last_bit = bit;
        }

        return last_bit;
    }
};



void test(int m, int n)
{
    cout << "input: m=" << m << ", n=" << n << "; output: ";
    int r = Solution().rangeBitwiseAnd(m, n);
    cout << r << ";" << endl;
}

int main(void)
{
    test(0, 0);
    test(5, 7);
    test(2147483646, 2147483647);
}

// Result 
//
// 2022-11-18: Runtime 18ms 34.47% Memory 5.9MB 66.70%, https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/845846448/
// 2023-02-22: Runtime 4ms 95.11% Memory 6MB 16.23%, https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/902646050/

