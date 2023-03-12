#include <lt_help/lt.h>

class Solution {
#define FOUR_MASK 0x55555555 // 01010101010101010101010101010101
public:
    bool isPowerOfFour(int num) {
        return isPowerOfTwo(num) && ((num | FOUR_MASK) == FOUR_MASK);
    }

    bool isPowerOfTwo(int n) {
        return n > 0 && ( (n&(n-1)) == 0 ); 
    }
};



void test(int n)
{
    cout << "input: " << n << "; output: "; 
    bool r = Solution().isPowerOfFour(n);
    cout << r << endl;
}


int main(void)
{ 
    test(16);
    test(5);
}

// Result 
//
// 2022-11-21: Runtime 3ms 52.21% Memory 5.9MB 83.17%, https://leetcode.com/problems/power-of-four/submissions/847192868/
// 2023-03-11: Runtime 0ms 100% Memory 6MB 62.25%, https://leetcode.com/problems/power-of-four/submissions/912965934/
