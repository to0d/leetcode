#include <lt_help/lt.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        for(; n > 1; n = n/3)
            if( n%3 != 0 )
                return false;
        return n == 1;
    }
};



void test(int n)
{
    cout << "input: " << n << "; output: "; 
    bool r = Solution().isPowerOfThree(n);
    cout << r << ";" << endl;
}


int main(void)
{ 
    test(27);
    test(0);
}

// Result 
//
// 2022-11-21: Runtime 39ms 19.64% Memory 6MB 63.27%, https://leetcode.com/problems/power-of-three/submissions/847194236/
// 2023-02-22: Runtime 24ms 58.94% Memory 6MB 63.68%, https://leetcode.com/problems/power-of-three/submissions/902745098/

