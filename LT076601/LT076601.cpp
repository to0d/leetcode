#include <lt_help/lt.h>

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        for(int i = 0; i < row; ++i )
            for(int j = 0; j < column; ++j )
                if( ((i+1) < row) && ((j+1) < column) && matrix[i+1][j+1] != matrix[i][j])
                    return false;
        return true;             
    }
};



void test(vector<vector<int>> matrix)
{
    cout << "input: ";
    outputVector(matrix);
    bool r = Solution().isToeplitzMatrix(matrix);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{1,2,3,4},{5,1,2,3},{9,5,1,2}});
}


// Result 
//
// 2022-12-06: Runtime 35ms 6.52% Memory 17.4MB 89.80%, https://leetcode.com/problems/toeplitz-matrix/submissions/855586298/
// 2023-02-24: Runtime 11ms 93.15% Memory 17.6MB 25.81%, https://leetcode.com/problems/toeplitz-matrix/submissions/904191411/



