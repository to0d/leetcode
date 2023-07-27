#include <lt_help/lt.h>

int calculate(int m, int n, int x, int y) {
    int s, val;
    int x2 = n - x - 1;
    int y2 = m - y - 1;
    int dx = std::min(x2,x);
    int dy = std::min(y2,y);
    int z = min(dx,dy);
    if( z > 0 )
        s = 2*(m+n)*z - 4*z*z;
    else
        s = 0;

    // up layer
    if( z == y || z == x2 )
        val = s + x + y - 2*z ;
    else
        val = s - x - y + 2*(m+n-2)-6*z;

    return val + 1;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for(int i = 0; i < n; ++i)
        {   vector<int> row;
            for(int j = 0; j <n ; ++j)
                row.push_back( calculate(n,n,j,i)); 
            matrix.push_back(row);
        }
        return matrix;
    }
};


void test(int n)
{
    cout << "input: " << n;
    vector<vector<int>> r = Solution().generateMatrix(3);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test(3);
}

// Result 
//
// 2022-11-16: Runtime 11ms 5.88% Memory 6.5MB 36.76%, https://leetcode.com/problems/spiral-matrix-ii/submissions/844279862/
// 2023-02-17: Runtime 3ms 71.79% Memory 6.5MB 38.46%, https://leetcode.com/problems/spiral-matrix-ii/submissions/899829078/
// 2023-07-27: Runtime 0ms 100% Memory 6.16MB 90.52%, https://leetcode.cn/problems/spiral-matrix-ii/submissions/

