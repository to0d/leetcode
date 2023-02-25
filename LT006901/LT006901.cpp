#include <lt_help/lt.h>

class Solution {
public:
    int mySqrt(int x) {
        long low = 0, high = INT_MAX;
        while( low <= high )
        {   long m = (low+high)/2;
            long m2 = m*m;
            if( m2 == x )
                return m;
            if( m2 < x )
                low = m+1;
            else
                high = m-1;
        }
        return high;
    }
};



void test(int x)
{
    cout << "input: " << x;
    int r = Solution().mySqrt(x);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(1024);
}


// Result 
//
// 2022-12-27: Runtime 3ms 68.68% Memory 5.9MB 92.10%, https://leetcode.com/problems/sqrtx/submissions/866365153/
// 2023-02-18: Runtime 0ms 100% Memory 6.1MB 8.51%, https://leetcode.com/problems/sqrtx/submissions/900088141/


