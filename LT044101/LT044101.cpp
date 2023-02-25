#include <lt_help/lt.h>

class Solution {
public:
    int arrangeCoins(int n) {
        if( n <= 0 ) 
            return 0;
    #define max_count(x) ((long long)(x))*(x+1)/2
    #define max_root     65535   // (max_root)(max_root+1)/2 < INT_MAX
    #define min(a,b)     ((a)<(b))?(a):(b)
        int l = 1, h = min(n,max_root);
        long long v;
        while( l < h )
        {   int m = (h-l)/2+l;
            v = max_count(m);
            if( v > INT_MAX ) // overflow
                h = m -1;
            else if( v == n )
                return m;
            else if( v < n )
            {   if( max_count(m+1) > n )
                    return m;
                else
                    l = m + 1;
            }
            else 
                h = m - 1;
        }

        return h;
    }
};


void test(int num)
{
    printf("input: %d", num);
    int r = Solution().arrangeCoins(num);
    printf("; output: %d\n", r);
}

int main(void)
{
    test(5);
}

// Result 
//
// 2022-11-19: Runtime 12ms 35.98% Memory 5.5MB 81.59%, https://leetcode.com/problems/arranging-coins/submissions/846392093/
// 2023-02-21: Runtime 0ms 100% Memory 6MB 8.91%, https://leetcode.com/problems/arranging-coins/submissions/901943747/




