#include <lt_help/lt.h>

// f(m,n) = f(m-1,n) + f(m,n-1)
// f(m,n) = 0, if grid[m][n] == 1
#define MAX_NUM 100
static int unique_nums[MAX_NUM][MAX_NUM] = {0};

int findUniquePaths(int** grid, int i, int j){
    if( i < 0 || j < 0 || grid[i][j] == 1) 
        return 0;

    int num = unique_nums[i][j];
    if( num == 0 )
    {   num = findUniquePaths(grid,i-1,j) + findUniquePaths(grid,i,j-1);
        if( num == 0 )
            num = -1;
        unique_nums[i][j] = num;
    }

    return num < 0 ? 0 : num;
} 

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if( obstacleGridSize == 0 || *obstacleGridColSize == 0 || obstacleGrid[0][0] == 1 ) 
        return 0;

    memset(unique_nums, 0, sizeof(unique_nums));
    unique_nums[0][0] = 1;
    return findUniquePaths(obstacleGrid,obstacleGridSize-1,*obstacleGridColSize-1);
}



void test(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    printf("input: ");
    outputArray2(obstacleGrid, obstacleGridSize, *obstacleGridColSize);
    int r = uniquePathsWithObstacles(obstacleGrid, obstacleGridSize, obstacleGridColSize);
    printf("; output: %d\n", r);
}

int main(void)
{
    int data[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int* obstacleGrid[3] = {data[0], data[1], data[2]};
    int obstacleGridColSize = 3;
    test(obstacleGrid, 3, &obstacleGridColSize);
}

// Result 
//
// 2022-11-19: Runtime 6ms 53.85% Memory 6MB 96.15%, https://leetcode.com/problems/unique-paths-ii/submissions/846158889/
// 2023-02-18: Runtime 0ms 100% Memory 6.3MB 29.33%, https://leetcode.com/problems/unique-paths-ii/submissions/900074227/
