#include <lt_help/lt.h>



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int row = matrix.size();
        int column = row == 0 ? 0 : matrix[0].size();
        int bound = column;
        
        for( int r = 0; bound > 0 && r < row; ++r )
        {   auto begin = matrix[r].begin();
            auto end = begin + bound;
            auto first = lower_bound(begin, end, target);
            if( *first == target)
                return true;
            bound = first - begin;
        }
        return false;
    }
};


void test(vector<vector<int>>& matrix, int target)
{
    cout << "input: matrix=";
    outputVector(matrix);
    cout << ", target=" << target << "; output: "; 
    bool r = Solution().searchMatrix(matrix, target);
    cout << r << ";" << endl;
}

int main(void)
{
   //vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
   //test(matrix1, 3);
    
    vector<vector<int>> matrix2 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    test(matrix2, 13);
}

// Result 
//
// 2022/11/18
//      Runtime Error
//      [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
//      13
