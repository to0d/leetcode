#include <lt_help/lt.h>

class Solution {
public:
    int trailingZeroes(int n) {
        return min(fm(n,5), fm(n,2));
    }
    
    int fm(int n, int m)
    {   int v = n/m;
        return v == 0 ? 0 : v + fm(v,m);
    }
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().trailingZeroes(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3);
    test(5);
}

// Result 
//
// 2022-11-21: Runtime 4ms 37.14% Memory 5.9MB 64.11%, https://leetcode.com/problems/factorial-trailing-zeroes/submissions/847497994/
// 2023-02-22: Runtime 0ms 100% Memory 6MB 64.20%, https://leetcode.com/problems/factorial-trailing-zeroes/submissions/902642620/
