#include <lt_help/lt.h>

// Fibonacci sequence
// f(n) = f(n-1) + f(n-2)
//     f(1) = 1
//     f(2) = 2
class Solution {
public:
    int climbStairs(int n) {
        if( n <= 2 ) 
            return n;
        int a = 1, b = 2;
        n -= 2;
        while( n-- > 0 )
        {   int t = a + b;
            a = b;
            b = t;
        }
        return b;
    }
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().climbStairs(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(2);
    test(3);
}

// Result 
//
// 2022-11-23: Runtime 2ms 46.56% Memory 5.5MB 45.97%, https://leetcode.com/problems/climbing-stairs/submissions/848336161/
// 2023-02-18: Runtime 0ms 100% Memory 6MB 44.80%, https://leetcode.com/problems/climbing-stairs/submissions/900089000/

