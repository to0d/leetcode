#include <lt_help/lt.h>

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();  
        if( row == 0 )
            return 0 ;
        
        int colum = grid[0].size(); 
        if ( colum == 0 ) 
            return 0 ;
        
        vector<int> visited(row*colum, 0); 
        int count = 0;
        
        for( int r = 0; r < row; ++r)
           for( int c = 0; c < colum; ++c )     
               if( grid[r][c] == '1' && visited[r*colum + c] == 0 )
               {
                    ++count;
                    stack<pair<int,int>> locStack;
                    locStack.push(make_pair(r,c));
                    visited[r*colum + c] = 1;

                    while( !locStack.empty())
                    {   pair<int,int> loc = locStack.top();
                        locStack.pop();
                        for( int i = 0; i < 4; ++i )
                        {   int xxr = loc.first + addR[i],  xxc = loc.second + addC[i];
                            if( xxr < row && xxr >= 0 
                             && xxc < colum && xxc >= 0 
                             && grid[xxr][xxc] == '1' 
                             && visited[xxr*colum + xxc] == 0)
                            {   locStack.push(make_pair(xxr,xxc));
                                visited[xxr*colum + xxc] = 1;
                            }
                        }
                    }
               }
        return count;
    }
    
    static int addR[4];
    static int addC[4];
};

int Solution::addR[4] = {1,0,-1,0};
int Solution::addC[4] = {0,1,0,-1};



void test(vector<vector<char>>& grid)
{
    cout << "input: ";
    outputVector(grid);
    int r = Solution().numIslands(grid);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    vector<vector<char>> board = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}};
    test(board);
}

// Result 
//
// 2022-11-21: Runtime 101ms 14.50% Memory 18.5MB 19.90%, https://leetcode.com/problems/number-of-islands/submissions/847500623/
// 2023-02-22: Runtime 61ms 21.42% Memory 18.6MB 20.9%, https://leetcode.com/problems/number-of-islands/submissions/902626890/


