#include <lt_help/lt.h>



class Solution {
public:
    int tribonacci(int n) {
        if( n == 0 ) return 0;
        if( n == 1 ) return 1;
        if( n == 2 ) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        for(int i = 2; i < n ;++i)
        {   int t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t2;
    }
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().tribonacci(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(4);
    test(25);
}


// Result 
//
// 2022-12-11: Runtime 0ms 100% Memory 5.9MB 95.86%, https://leetcode.com/problems/n-th-tribonacci-number/submissions/857934111/


