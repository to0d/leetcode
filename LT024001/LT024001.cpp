#include <lt_help/lt.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), column = matrix[0].size();
        int c_max = indexOfRow(matrix, target, 0, 0, column-1, true);
        int c_min = indexOfRow(matrix, target, row-1, 0, column-1, false);
        int r_max = indexOfColumn(matrix, target, 0, 0, row-1, true);
        int r_min = indexOfColumn(matrix, target, column-1, 0, row-1, false);
        for(int r = r_min; r <= r_max; ++r)
        {   int c = indexOfRow(matrix, target, r, c_min, c_max, true);
            if( matrix[r][c] == target )
                return true;
        }     

        return false;
    }
    
    int indexOfRow(vector<vector<int>>& matrix, int t, int row, int l, int h, bool low) {
        while( l <= h )
        {   int m = (l+h)/2; 
            int m2 = matrix[row][m];
            if ( t == m2 )
                return m;
            if ( t > m2 )
                l = m + 1;
            else 
                h = m - 1;
        }
        return low ? h : l;
    }

    int indexOfColumn(vector<vector<int>>& matrix, int t, int column, int l, int h, bool low) {
        while( l <= h )
        {   int m = (l+h)/2; 
            int m2 = matrix[m][column];
            if ( t == m2 )
                return m;
            if ( t > m2 )
                l = m + 1;
            else 
                h = m - 1;
        }
        return low ? h : l;
    }
};



void test(vector<vector<int>> matrix, int target)
{
    cout << "input: matrix=";
    outputVector(matrix);
    cout << ", target=" << target << "; output: "; 
    bool r = Solution().searchMatrix(matrix, target);
    cout << r << ";" << endl;
}

int main(void)
{
    test({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 5);
}

// Result 
//
// 2022-11-18: Runtime 343ms 13.41% Memory 15MB 39.34%, https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/845860925/
// 2023-02-22: Runtime 247ms 20.47% Memory 15MB 39.86%, https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/902726798/
// 2023-03-12: Runtime 181ms 22.24% Memory 14.9MB 73.33%, https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/913730022/



