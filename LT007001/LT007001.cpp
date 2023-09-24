#include <lt_help/lt.h>

class Solution {
public:
    // f(n) = f(n-1) + f(n-2) // Fibonacci sequence
    int climbStairs(int n) {
        int a = 1, b = 1;
        while(--n > 0){
            int c = a + b;
            a = b;
            b = c;
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
// 2023-09-24: Runtime 0ms 100% Memory 6.10MB 7.86%, https://leetcode.cn/problems/climbing-stairs/submissions/469199126/

