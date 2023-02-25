#include <lt_help/lt.h>



class Solution {
public:
    int bitwiseComplement(int n) {
        if( n == 0 )
            return 1;
        int b = 0;
        for(int nn = n ; nn > 0; nn = nn >> 1)
            b = (b << 1) | 1;
        //cout << "b=" << b << ", ~n=" << ~n << endl;
        return ~n & b;
    }
};


void test(int n)
{
    cout << "input: " << n;
    int r = Solution().bitwiseComplement(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(5);
}


// Result 
//
// 2022-12-07: Runtime 0ms 100% Memory 5.9MB 66.80%, https://leetcode.com/problems/complement-of-base-10-integer/submissions/856170490/



