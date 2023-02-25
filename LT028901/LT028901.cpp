#include <lt_help/lt.h>



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int x[] = {1, 0,-1,-1,-1, 0, 1, 1};
        int y[] = {1, 1, 1, 0,-1,-1,-1, 0};
        int n = board.size();
        if( n == 0 ) 
            return;
        int m = board[0].size();
        if( m == 0 )
            return;
        
        for( int i = 0; i < n; ++i )
        {   for( int j = 0; j < m; ++j )
            {   int c = 0;
                int& v = board[i][j];
                for( int k = 0; k < 8; ++k )
                {   int ii = i + x[k];
                    int jj = j + y[k];
                    if( ii >=0 && ii < n && jj >=0 && jj < m )
                    {   c += board[ii][jj] & 0xF;
                    }
                }
                if( (v > 0 && (c == 2 || c == 3 )) || (v == 0 && c == 3))
                {   v |= 0x10;
                }
            }
        }
        for( auto& row : board )
        {   for( int& v : row )
            {   v = v >> 4;
            }
        }
    }
};


void test(vector<vector<int>> board)
{
    cout << "input: ";
    outputVector(board);
    cout << "; output: "; 
    Solution().gameOfLife(board);
    outputVector(board);
    cout << ";" << endl;
}

int main(void)
{
    test({{1,1},{1,0}});
}


// Result 
//
// 2022-11-11: Runtime 0ms 100% Memory 7MB 64.88%, https://leetcode.com/problems/game-of-life/submissions/844625793/

