#include <lt_help/lt.h>


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), colum = obstacleGrid[0].size();
        if( obstacleGrid[0][0] == 1 )
            return 0;
        
        static int dp[2*100];                   // optimization: only use 2 static row - 2023/07/27
#define dpf(i, j) dp[((i)%2)*colum + (j)]   
#define obs(i, j) obstacleGrid[(i)][(j)]
         
        bool obs_column = false;
        for(int j = 0;j < colum; ++j)
        {   if( !obs_column && obs(0, j) == 1 )
                obs_column = true;
            dpf(0, j) = obs_column ? 0 : 1;
        }

        int obs_row = false;
        for(int i = 1;i < row; ++i)
        {   if( !obs_row && obs(i, 0) == 1 )
                obs_row = true;
            dpf(i, 0) = obs_row ? 0 : 1;
            for(int j = 1;j < colum; ++j)
                if( obs(i, j) == 1 )
                    dpf(i, j) = 0;
                else 
                    dpf(i, j) = dpf(i-1, j)+dpf(i, j-1); 
        }
        
        return dpf(row-1, colum-1);
    }
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
//
// 2023-02-18: Runtime 0ms 100% Memory 9.4MB 16.53%, https://leetcode.com/problems/unique-paths-ii/submissions/900079277/
// 2023-05-15: Runtime 3ms 73.28% Memory 7.6MB 92.51%, https://leetcode.com/problems/unique-paths-ii/submissions/950600404/
// 2023-07-27: Runtime 0ms 7.29% Memory 7.13MB 96.11%, https://leetcode.cn/problems/unique-paths-ii/submissions/450762359

