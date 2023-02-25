#include <lt_help/lt.h>

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), maxArea = 0;
        for(int i = 0; i < row; ++i )
            for(int j = 0; j < column; ++j )
                if( grid[i][j] == 1 )
                    maxArea = std::max(maxArea, _areaOf(grid, row, column, i, j));
        return maxArea;
    }
    
    int _areaOf(vector<vector<int>>& grid, int row, int column, int r, int c) {   
        queue<int> rq, cq;
        rq.push(r); cq.push(c);
        int count = 0;
        while( !rq.empty() )
        {   int rr = rq.front(); rq.pop();
            int cc = cq.front(); cq.pop();
            if( rr < 0 || rr >= row || cc < 0 || cc >= column )
                continue;
            if( grid[rr][cc] == 0 )
                continue;
            grid[rr][cc] = 0;
            ++count;
            rq.push(rr); cq.push(cc+1);
            rq.push(rr); cq.push(cc-1);
            rq.push(rr+1); cq.push(cc);
            rq.push(rr-1); cq.push(cc);
        }
        return count;
    }
};



void test(vector<vector<int>> grid)
{
    cout << "input: "; 
    outputVector(grid); 
    int r = Solution().maxAreaOfIsland(grid);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({{0,1,1,0}, {0,0,1,0}});
}

// Result 
//
// 2023-01-19: Runtime 31ms 29.81% Memory 30.9MB 6.76%, https://leetcode.com/problems/max-area-of-island/submissions/880970748/
// 2023-02-25: Runtime 23ms 58.17% Memory 30.8MB 6.27%, https://leetcode.com/problems/max-area-of-island/submissions/904432298/



