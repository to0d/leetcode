#include <lt_help/lt.h>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();  
        vector<int> dp(m*n, 0);
#define dpf(i, j) dp[(i)*n + (j)]
#define obs(i, j) obstacleGrid[(i)][(j)]
        bool obs_row = false;
        for(int i = 0;i < m; ++i)
        {   if( !obs_row && obs(i, 0) == 1 )
                obs_row = true;
            dpf(i, 0) = obs_row ? 0 : 1;
        }
        bool obs_column = false;
        for(int j = 0;j < n; ++j)
        {   if( !obs_column && obs(0, j) == 1 )
                obs_column = true;
            dpf(0, j) = obs_column ? 0 : 1;
        } 
        for(int i = 1;i < m; ++i)
            for(int j = 1;j < n; ++j)
                if( obs(i, j) == 1 )
                    dpf(i, j) = 0;
                else 
                    dpf(i, j) = dpf(i-1, j)+dpf(i, j-1); 
        return dpf(m-1, n-1);
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

