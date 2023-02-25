#include <lt_help/lt.h>



class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        for(; n > 0 ; n = n >> 1)
        {   int bit = n & 1;
            if( bit == last )
                return false;
            last = bit;
        }

        return true;
    }
};


void test(int n)
{
    cout << "input: " << n;
    bool r = Solution().hasAlternatingBits(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(5);
}


// Result 
//
// 2022-12-01: Runtime 0ms 100% Memory 5.8MB 83.14%, https://leetcode.com/problems/binary-number-with-alternating-bits/submissions/852601604/



