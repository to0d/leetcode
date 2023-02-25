#include <lt_help/lt.h>

class Solution {

public:
    double myPow(double x, long n) {
        static float MIN_FLOAT = numeric_limits<float>::min();
        static float MAX_FLOAT = numeric_limits<float>::max();

        if( n == 0)
            return 1;
        
        if( n == -2147483648)
        {   x = std::abs(x);
            if( x > ( 1 + MIN_FLOAT) )
                return 0;
            else if ( x >= 1- MIN_FLOAT)
                return 1;
            else 
                return MAX_FLOAT;
        }
            
        if( n < 0 )
            return myPow(1/x, -n);
        
        if( std::abs( x - 1 ) < MIN_FLOAT )
            return 1;
        
        if( std::abs( x + 1 ) < MIN_FLOAT )
            return n % 2 == 1 ? -1 : 1;
        
        double r = 1;
        for( int i = 0 ; i < n; ++i)
        {   r *= x;
            if( std::abs( r ) < MIN_FLOAT )
                return 0;
        }

        return r;
    }
};



void test(double x, long n)
{
    cout << "input: x=" << x << ", n=" << n;
    double r = Solution().myPow(x, n);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test(2.00000, 10); 
}

// Result 
//
// 2022-11-21: Runtime 5ms 10.32% Memory 6MB 76.86%, https://leetcode.com/problems/powx-n/submissions/846971249/
// 2023-02-17: Runtime 8ms 5.58% Memory 6.1MB 34.87%, https://leetcode.com/problems/powx-n/submissions/899811951/

