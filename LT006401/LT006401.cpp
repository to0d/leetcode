#include <lt_help/lt.h>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        for(int i = 1; i < row; ++i)
            grid[i][0] += grid[i-1][0];
        for(int j = 1; j < column; ++j)
            grid[0][j] += grid[0][j-1];        
        for(int i = 1; i < row; ++i)
            for(int j = 1; j < column; ++j)
                grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
        return grid[row-1][column-1];
    }
};



void test(vector<vector<int>> grid)
{
    cout << "input: ";
    outputVector(grid);
    int r = Solution().minPathSum(grid);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{1,3,1},{1,5,1},{4,2,1}});
}


// Result 
//
// 2022-12-05: Runtime 11ms 65.8% Memory 9.6MB 98.58%, https://leetcode.com/problems/minimum-path-sum/submissions/854772187/
// 2023-02-18: Runtime 11ms 63.32% Memory 9.6MB 98.67%, https://leetcode.com/problems/minimum-path-sum/submissions/900079926/
// 2023-03-12: Runtime 7ms 90.48% Memory 9.7MB 91.86%, https://leetcode.com/problems/minimum-path-sum/submissions/913491254/



