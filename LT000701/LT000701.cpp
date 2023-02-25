#include <lt_help/lt.h>



// INT_MIN (-2147483648)  
// INT_MAX (2147483647)  

class Solution {
public:
    int reverse(int x) {
        if( x == INT_MIN ) 
            return 0;

        if( x < 0 ) 
            return -reverse(-x);

        long long r = 0;
        for(; x > 0; x /= 10)
        {   r = r*10+x%10;
            if( r > INT_MAX)
               return 0;
        }

        return (int)r;
    }
};

void test(int x)
{
    cout << "input: " << x;
    int r = Solution().reverse(x);
    cout << "; output: " << r << endl;
}

int main(void)
{  
    test(123);
}

// Result 
//
// 2023-02-09: Runtime 0ms 100% Memory 6MB 64.22%, https://leetcode.com/problems/reverse-integer/submissions/894759591/


