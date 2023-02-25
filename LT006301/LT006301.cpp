#include <lt_help/lt.h>

class Solution {
public:
#define MAX_NUM 100
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = m == 0 ? 0 : obstacleGrid[0].size();
        if( m == 0 || n == 0 || obstacleGrid[0][0] == 1)
            return 0;
        unique_nums.clear();
        unique_nums.assign(MAX_NUM*MAX_NUM, 0);
        unique_nums[0] = 1;

        return uniquePaths(obstacleGrid,m-1,n-1);
    }

    int uniquePaths(vector<vector<int>>& grid, int i, int j) {
        if( i < 0 || j < 0 || grid[i][j] == 1) 
            return 0;

        int num = unique_nums[i*MAX_NUM+j];
        if( num == 0 )
        {   num = uniquePaths(grid, i-1,j)+uniquePaths(grid, i,j-1);
            if( num == 0 )
                num = -1;
            unique_nums[i*MAX_NUM+j] = num;
        }

        return num < 0 ? 0 : num;
    }
    
    vector<int> unique_nums;
};



void test(vector<vector<int>> obstacleGrid)
{
    cout << "input: ";
    outputVector(obstacleGrid);
    cout << "; output: "; 
    int r = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << r << ";" << endl;
}

int main(void)
{
    test({{0,0,0},{0,1,0},{0,0,0}});
}

// Result 
//
// 2022/11/19
//
// 2023-02-18: Runtime 0ms 100% Memory 9.4MB 16.53%, https://leetcode.com/problems/unique-paths-ii/submissions/900079277/

