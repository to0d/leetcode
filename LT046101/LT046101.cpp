#include <lt_help/lt.h>

class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitNumOf(x ^ y);
    }
    
    int bitNumOf(int n) {
        int sum = 0;
        for (; n!= 0; n &= (n-1))
            ++sum;
        return sum;
    }
};



void test(int x, int y)
{
    cout << "input: x=" << x << ", y=" << y;
    int r = Solution().hammingDistance(x, y);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(1, 4);
}


// Result 
//
// 2023-03-11: Runtime 0ms 100% Memory 5.9MB 93.7%, https://leetcode.com/problems/hamming-distance/submissions/913270065/
// 2023-07-26: Runtime 0ms 100% Memory 5.60MB 86.54%, https://leetcode.cn/problems/hamming-distance/submissions/450340978/



