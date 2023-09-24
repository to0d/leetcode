#include <lt_help/lt.h>

class Solution {
public:
    // f(i, j) = min( f(i-1, j), f(i, j-1)) + grid(i, j)
    //         = f(i-1, 0) + grid(i, 0) when j == 0
    //         = f(0, j-1) + grid(0, j) when i == 0
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> arr(1, grid[0][0]);
        for(int j = 1; j < n; ++j )
            arr.push_back(grid[0][j]+arr[j-1]);
        for(int i = 1; i < m; ++i )
            for(int j = 0; j < n; ++j )
                arr[j] = (j == 0 ? arr[j] : min(arr[j], arr[j-1])) + grid[i][j];
        return arr[n-1];
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
// 2023-09-24: Runtime 4ms 98.44% Memory 9.51MB 64.33%, https://leetcode.cn/problems/minimum-path-sum/submissions/469196401



