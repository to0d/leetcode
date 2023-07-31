#include <lt_help/lt.h>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int count[3][9][9] = {0}, v;
        for( int r = 0; r < 9; ++r)
        {   for( int c = 0; c < 9; ++c)
            {   if( (v=board[r][c]) == '.' )
                    continue;
                int val = v - '1';
                if( count[0][r][val]++ != 0 
                    || count[1][c][val]++ != 0 
                    || count[2][(r/3)*3+c/3][val]++ != 0 )
                return false;
            }
        }
        return true;
    }
};

void test(vector<vector<char>> board)
{
    cout << "input: ";
    outputVector(board);
    auto r = Solution().isValidSudoku(board);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test({{'5','3','.','.','7','.','.','.','.'}
         ,{'6','.','.','1','9','5','.','.','.'}
         ,{'.','9','8','.','.','.','.','6','.'}
         ,{'8','.','.','.','6','.','.','.','3'}
         ,{'4','.','.','8','.','3','.','.','1'}
         ,{'7','.','.','.','2','.','.','.','6'}
         ,{'.','6','.','.','.','.','2','8','.'}
         ,{'.','.','.','4','1','9','.','.','5'}
         ,{'.','.','.','.','8','.','.','7','9'}});
    
}

// Result 
//
// 2023-07-31: Runtime 4ms 99.94% Memory 17.15MB 52.86%, https://leetcode.cn/problems/valid-sudoku/submissions/451849632/


    