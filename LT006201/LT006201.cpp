#include <lt_help/lt.h>

// f(m,n) = f(m-1,n) + f(m,n-1)
// f(m,n) = f(n,m)
// f(1,n) = 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        if( m == 0 || n == 0 ) return 0;
        if( n == 1 ) return 1;
        vector<int> dp(m*n, 0);
#define dpf(i, j) dp[(i)*n + (j)]
        for(int i = 0;i < m; ++i)
            dpf(i, 0) = 1;
        for(int j = 0;j < n; ++j)
            dpf(0, j) = 1;
        for(int i = 1;i < m; ++i)
            for(int j = 1;j < n; ++j)
                dpf(i, j) = dpf(i-1, j)+dpf(i, j-1);
        return dpf(m-1, n-1);
    }
};



void test(int m, int n)
{
    cout << "input: m=" << m << ", n=" << n;
    int r = Solution().uniquePaths(m, n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3, 7);
}

// Result 
//
// 2023-02-18: Runtime 3ms 39% Memory 6MB 88.94%, https://leetcode.com/problems/unique-paths/submissions/900072253/
// 2023-03-13: Runtime 0ms 100% Memory 6.5MB 54.23%, https://leetcode.com/problems/unique-paths/submissions/913922560/

