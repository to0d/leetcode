#include <lt_help/lt.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) 
            return false;
        return x == reverse(x);
    }
    
    int reverse(int x) {
        if( x == INT_MIN ) return 0;
        if( x < 0 ) return -reverse(-x);

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
    bool rc = Solution().isPalindrome(x);
    cout << "; output: " << rc << ";" << endl;
}

int main(void)
{
    test(-121);
    test(10);
    test(121);
    test(1234567899);
}

// Result 
//
// 2023-02-09: Runtime 14ms 69.88% Memory 6MB 62%, https://leetcode.com/problems/palindrome-number/submissions/894772460/
// 2023-03-11: Runtime 12ms 77.83% Memory 5.9MB 63.24%, https://leetcode.com/problems/palindrome-number/submissions/912989942/


