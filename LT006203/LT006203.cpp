#include <lt_help/lt.h>

class Solution {
#define MAX_NUM 100
public:
    int uniquePaths(int m, int n) {
        if( m == 0 || n == 0 ) 
            return 0;
        if( m < n )  
            return uniquePaths(n, m);
        if( n == 1 ) 
            return 1;
        
        static vector<int> unique_nums(MAX_NUM*MAX_NUM, 0);
        int num = unique_nums[(m-1)*MAX_NUM+n-1];
        if( num == 0 )
            num = uniquePaths(m-1,n)+uniquePaths(m,n-1);

        unique_nums[(m-1)*MAX_NUM+n-1] = num;
        return num;
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

