#include <lt_help/lt.h>



// 2  ==> 00000010
// 4  ==> 00000100
// 8  ==> 00001000
// 16 ==> 00010000
// 
// 2^n ==> 0001000000000
//             |<- n ->|
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ( (n&(n-1)) == 0 ); 
    }
};

void test(int n)
{
    cout << "input: " << n << "; output: "; 
    bool r = Solution().isPowerOfTwo(n);
    cout << r << endl;
}


int main(void)
{
    test(1); 
    test(16);
    test(3);
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 5.8MB 97.61%, https://leetcode.com/problems/power-of-two/submissions/846312881/

