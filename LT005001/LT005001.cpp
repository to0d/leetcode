#include <lt_help/lt.h>

class Solution {

public:
    double myPow(double x, int n) {
        long long z = n;
        return z < 0 ? (1.0 / _myPow(x, -z) ) : _myPow(x, z);
    }
    
    double _myPow(double x, long long n) {
        double r = 1, tmp = x;
        while( n > 0 )
        {   if( n & 1 )
                r *= tmp;
            tmp = tmp*tmp;     // <== opt
            n = n >> 1;
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
// 2023-03-10: Runtime 0ms 100% Memory 6MB 77.87%, https://leetcode.com/problems/powx-n/submissions/912742706/



