#include <lt_help/lt.h>

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;

        int a = 0, b = 1;
        for(int i = 1 ; i < n ; ++i )
        {   int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};



void test(int n)
{
    cout << "input: " << n << "; output: ";
    int r = Solution().fib(n);
    cout << r << ";" << endl;
}

int main(void)
{
    test(3);
}

// Result 
//
// 2022-11-25: Runtime 99ms 27.21% Memory 9.4MB 94.39%, https://leetcode.com/problems/repeated-substring-pattern/submissions/849528528/
// 2023-02-24: Runtime 0ms 100% Memory 5.9MB 93.79%, https://leetcode.com/problems/fibonacci-number/submissions/904149940/
