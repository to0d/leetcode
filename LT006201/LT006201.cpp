#include <lt_help/lt.h>

class Solution {
public:
    // f(n, m) = f(n-1, m) + f(n, m-1)
    //         = 1    when n = 0 or m = 0
    int uniquePaths(int m, int n) {
        vector<int> arr (n, 1);
        for(int i = 1; i < m; ++i )
            for(int j = 1; j < n; ++j)
                arr[j] += j == 1 ? 1 : arr[j-1];
        return arr[n-1];
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
// 2023-09-24: Runtime 0ms 100% Memory 6.24MB 33.62%, https://leetcode.cn/problems/unique-paths/submissions/469192483/

