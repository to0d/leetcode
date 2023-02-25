#include <lt_help/lt.h>

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();  
        if( row == 0 ) 
            return;
        int colum = board[0].size(); 
        if ( colum == 0 ) 
            return;
        
        vector<int> visited( row*colum, 0);
        for( int r = 0; r < row; ++r)
        {   for( int c = 0; c < colum; ++c )
            {   if( board[r][c] == 'O' && visited[r*colum + c] == 0 )
                {
                    int touchSide = 0;
                    stack<pair<int,int>> locStack;
                    vector<pair<int,int>> visitedLoc;
                    locStack.push(make_pair(r,c));
                    visited[r*colum + c] = 1;

                    while( !locStack.empty())
                    {
                        pair<int,int> loc = locStack.top();
                        locStack.pop();
                        visitedLoc.push_back(loc);
                        
                        int xr(loc.first), xc(loc.second);
                        if( xr == 0 || xr == (row-1) || xc == 0 || xc == (colum-1))
                            ++touchSide;
                        
                        for( int i = 0; i < 4; ++i )
                        {
                            int xxr = xr + addR[i];
                            int xxc = xc + addC[i];
                            if( xxr < row && xxr >= 0 
                             && xxc < colum && xxc >= 0 
                             && board[xxr][xxc] == 'O' 
                             && visited[xxr*colum + xxc] == 0)
                            {
                                 locStack.push(make_pair(xxr,xxc));
                                 visited[xxr*colum + xxc] = 1;
                            }
                        }
                    }
                    
                    if( touchSide == 0 )
                    {
                        for( auto& p : visitedLoc)
                             board[p.first][p.second] = 'X';
                    }
                }
            }
        }
    }

    static int addR[4];
    static int addC[4];
};

int Solution::addR[4] = {1,0,-1,0};
int Solution::addC[4] = {0,1,0,-1};



void test(vector<vector<char>> board)
{
    cout << "input: ";
    outputVector(board);
    cout << "; output: "; 
    Solution().solve(board);
    outputVector(board);
    cout << ";" << endl;
}

int main(void)
{
    test({{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}});
}

// Result 
//
// 2022-11-18: Runtime 17ms 42.52% Memory 12.2MB 15.62%, https://leetcode.com/problems/surrounded-regions/submissions/845838382/
// 2023-02-22: Runtime 15ms 59.24% Memory 12.2MB 13.57%, https://leetcode.com/problems/surrounded-regions/submissions/902641366/



