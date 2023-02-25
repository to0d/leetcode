#include <lt_help/lt.h>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m == 0? 0 : matrix[0].size();

        vector<int> rst;
        int m0 = 0, n0 = 0, m1 = m-1, n1 = n-1;
        for(; m0 < m1 && n0 < n1; m0++, n0++, m1--, n1--)
        {   for(int i = n0; i <=n1; ++i)
                rst.push_back(matrix[m0][i]);
            for(int i = m0+1; i<=m1; ++i)
                rst.push_back(matrix[i][n1]);
            for(int i = n1-1; i>=n0; --i)
                rst.push_back(matrix[m1][i]);
            for(int i = m1-1; i>m0; --i)
                rst.push_back(matrix[i][n0]); 
        }
        
        if( m0 == m1 && n0 == n1 )
            rst.push_back(matrix[m0][n0]); 
        else if ( m0 == m1 && n0 < n1 )
            for(int i = n0; i <=n1; ++i)
                rst.push_back(matrix[m0][i]);
        else if ( m0 < m1 && n0 == n1 )
            for(int i = m0; i<=m1; ++i)
                rst.push_back(matrix[i][n1]);

        return rst;
    }
};



void test(vector<vector<int>> matrix)
{
    cout << "input: ";
    outputVector(matrix);
    cout << "; output: ";
    vector<int> r = Solution().spiralOrder(matrix);
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test({{1,2,3,4},{5,6,7,8},{9,10,11,12}}); 
}

// Result 
//
// 2022-11-16: Runtime 0ms 100% Memory 7MB 34.35%, https://leetcode.com/problems/spiral-matrix/submissions/844273068/
// 2023-02-17: Runtime 0ms 100% Memory 6.9MB 34.56%, https://leetcode.com/problems/spiral-matrix/submissions/899818906/

