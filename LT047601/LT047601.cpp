#include <lt_help/lt.h>

class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        for(int t = num >> 1; t != 0; t >>= 1)
            mask = mask << 1 | 1;
        return ~num & mask;
    }
};


void test(int num)
{
    cout << "input: " << num;
    int r = Solution().findComplement(num);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(5);
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 5.6MB 34.17%, https://leetcode.com/problems/number-complement/submissions/846390539/
// 2023-07-26: Runtime 0ms 100% Memory 5.63MB 70.90%, https://leetcode.cn/problems/number-complement/submissions/450336202/
