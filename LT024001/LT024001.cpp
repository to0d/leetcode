#include <lt_help/lt.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = row == 0 ? 0 : matrix[0].size();
        int r = 0, v = 0;
        for(r = 0; r < row; ++r )
        {   v = matrix[r][0];
            if( v > target )  return false;
            if( v == target ) return true;
            v = matrix[r][column-1] ;
            if( v == target ) return true;
            if( v > target )  break;
        }

        for(int bound = column ; bound > 0 && r < row; ++r )
        {   auto begin = matrix[r].begin();
            auto end = begin + bound;
            auto first = lower_bound(begin, end, target);
            if(first != end && *first == target)
                return true;
            bound = first - begin;
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
    test({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, 5);
}

// Result 
//
// 2022-11-18: Runtime 343ms 13.41% Memory 15MB 39.34%, https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/845860925/
// 2023-02-22: Runtime 247ms 20.47% Memory 15MB 39.86%, https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/902726798/


