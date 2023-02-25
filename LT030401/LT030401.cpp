#include <lt_help/lt.h>

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        column = row == 0 ? 0 : matrix[0].size();
        for( int r = 0; r < row; ++r )
        {   int lineSum = 0;
            vector<int>& line = matrix[r];
            for( int c = 0 ; c < column; ++c )
            {   lineSum += line[c];
                sumMatrix.push_back( lineSum + getSum( r-1, c));
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {   
        return getSum(row2, col2) + getSum(row1-1, col1-1) - getSum(row2, col1-1) - getSum(row1-1, col2);
    }
    
    int getSum(int r, int c){   
        return (r < 0 || c < 0 ) ? 0 : sumMatrix[r*column + c];
    }

    vector<int> sumMatrix;
    int row;
    int column;
};



vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
NumMatrix numMatrix(matrix);

void test(int row1, int col1, int row2, int col2)
{
    cout << "input: row1=" << row1 << ", col1=" << col1 << ", row2=" << row2 << ", col2=" << col2;
    int r = numMatrix.sumRegion(row1, col1, row2, col2);
    cout << "; output: "; 
    cout << r << ";" << endl;
}

int main(void)
{
    test(2, 1, 4, 3);
   //test(1, 1, 2, 2);
   //test(1, 2, 2, 4);
}


// Result 
//
// 2022-11-16: Runtime 926ms 7.67% Memory 146.3MB 6.33%, https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/844634754/
// 2023-02-22: Runtime 499ms 22.65% Memory 146.2MB 6.85%, https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/902739782/



