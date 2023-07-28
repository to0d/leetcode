#include <lt_help/lt.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t val = 0;
        for(int i = 0; i < 32;++i, n >>= 1)
           val =  (val << 1) | (n&1);
        return val;
    }
}; 


void test(uint32_t n)
{
    cout << "input: " << n;
    uint32_t r = Solution().reverseBits(n);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(43261596);
}

// Result 
//
// 2022-11-19: Runtime 3ms 60.80% Memory 6.1MB 36.73%, https://leetcode.com/problems/reverse-bits/submissions/846357313/
// 2023-07-28: Runtime 0ms 100% Memory 5.62MB 82.88%, https://leetcode.cn/problems/reverse-bits/submissions/451110875/

