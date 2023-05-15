#include <lt_help/lt.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row    = matrix.size();
        int column = (row == 0 ? 0 : matrix[0].size());
        int bound  = column;
        int l, h, m, v, idx;
        
        if( matrix[0][0] > target ||  matrix[row-1][column-1] < target )
            return false;
         
        l = 0, h = row-1;
        while( l <= h )
        {   m = (l+h)/2; 
            v = matrix[m][0];
            if ( target > v )
                l = m + 1;
            else if( target < v )
                h = m - 1;
            else
                return true;
        }
        
        idx = h;
        
        l = 0, h = row-1;
        while( l <= h)
        {   m = (l+h)/2;
            v = matrix[m][column-1];
            if ( target > v )
                l = m + 1;
            else if( target < v )
                h = m - 1;
            else
                return true;
        }
        
        if( idx != l )
            return false;
            
        l = 0, h = column;
        while( l <= h)
        {   m = (l+h)/2;
            v = matrix[idx][m];
            if ( target > v )
                l = m + 1;
            else if( target < v )
                h = m - 1;
            else
                return true;
        }

        return false;
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
    test({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13);
}

// Result 
//
// 2023-05-15: Runtime 5ms 54.78% Memory 9.5MB 49.70%, 

