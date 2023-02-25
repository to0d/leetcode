#include <lt_help/lt.h>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){   
        int i0 = 0, j0 = 0, m=matrix.size(), n=matrix[0].size();
        if( 0 == m || 0 == n )
            return;
        
        for( int i = 0; i0 == 0 && i < m; ++i)
            if( 0 == matrix[i][0])
                i0 = 1;

        for( int j = 0; j0 ==0 && j < n; ++j )
            if( 0 == matrix[0][j])
                j0 = 1; 

        for( int i = 1; i < m; ++i)
            for( int j = 1; j < n; ++j )
                if( 0 == matrix[i][j])
                {   matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for( int i = 1; i < m; ++i)
            for( int j = 1; j < n; ++j )
                if( 0 != matrix[i][j] && (0 == matrix[i][0] || 0 == matrix[0][j] ))
                    matrix[i][j] = 0;

        if( i0 == 1 )
            for( int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        
        if( j0 == 1 )
            for( int j = 0; j < n; ++j )
                matrix[0][j] = 0;
    }
};



void test(vector<vector<int>> matrix)
{
    cout << "input: ";
    outputVector(matrix);
    Solution().setZeroes(matrix);
    cout << "; output: ";
    outputVector(matrix);
    cout << ";" << endl;
}

int main(void)
{
    test({{0,1,2,0},{3,4,5,2},{1,3,1,5}});
}

// Result 
//
// 2022-11-23: Runtime 31ms 12.17% Memory 13.2MB 72.52%, https://leetcode.com/problems/set-matrix-zeroes/submissions/848337637/
// 2023-02-18: Runtime 8ms 96.99% Memory 13.3MB 73.70%, https://leetcode.com/problems/set-matrix-zeroes/submissions/900093756/



