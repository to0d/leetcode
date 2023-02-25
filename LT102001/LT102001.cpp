#include <lt_help/lt.h>



class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        
        // remove all other land on boundary
        queue<int> rq, cq;
        for(int i = 0; i < row; ++i)
        {   rq.push(i); cq.push(0);
            rq.push(i); cq.push(column-1);
        }
        for(int i = 0; i < column; ++i)
        {   rq.push(0); cq.push(i);
            rq.push(row-1); cq.push(i);
        }
        while( !rq.empty() )
        {   int r = rq.front(); rq.pop();
            int c = cq.front(); cq.pop();
            if( grid[r][c] == 0 )
                continue;
            // cout << "remove: r=" << r << ", c=" << c << endl;
            grid[r][c] = 0;
            for( int i = 0; i < 4; ++i )
            {  int xxr = r + addR[i];
               int xxc = c + addC[i];
               if( xxr < row && xxr >= 0 && xxc < column && xxc >= 0)
               {   rq.push(xxr); cq.push(xxc);
               }
            }
        }
        int count = 0;
        for(int i = 0; i < row; ++i )
        {   for(int j = 0; j < column; ++j )
            {   if( grid[i][j] == 1 )
                    count += _areaOf(grid, row, column, i, j);
            }
        }
        return count;
    }
    
    int _areaOf(vector<vector<int>>& grid, int row, int column, int r, int c)
    {   queue<int> rq, cq;
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
    
    static int addR[4];
    static int addC[4];
};

int Solution::addR[4] = {1,0,-1,0};
int Solution::addC[4] = {0,1,0,-1};


void test(vector<vector<int>> grid)
{
    cout << "input: "; 
    outputVector(grid); 
    int r = Solution().numEnclaves(grid);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}});
}

// Result 
//
// 2023-01-31: Runtime 158ms 15.84% Memory 71.8MB 5.2%, https://leetcode.com/problems/number-of-enclaves/submissions/888706253/

