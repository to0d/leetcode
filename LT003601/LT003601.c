#include <lt_help/lt.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
    if( boardRowSize !=9 || boardColSize != 9 )
    {   return false;
    }
    
    int count[3][9][9] = {0};
    int v;
    
    for( int r = 0; r < 9; ++r)
    {   for( int c = 0; c < 9; ++c)
        {   if( (v=board[r][c])=='.' )
            {   continue;
            }
            int vi = v - '1';
            if( vi < 0 || vi >= 9 
                || count[0][r][vi]++ != 0 
                || count[1][c][vi]++ != 0 
                || count[2][r/3*3+c/3][vi]++ != 0 )
            {   return false;
            }
        }
    }
    return true;
}

int main(void)
{
    //char board[9][9] = 
    //    {{'5','3','.','.','7','.','.','.','.'}
    //    ,{'6','.','.','1','9','5','.','.','.'}
    //    ,{'.','9','8','.','.','.','.','6','.'}
    //    ,{'8','.','.','.','6','.','.','.','3'}
    //    ,{'4','.','.','8','.','3','.','.','1'}
    //    ,{'7','.','.','.','2','.','.','.','6'}
    //    ,{'.','6','.','.','.','.','2','8','.'}
    //    ,{'.','.','.','4','1','9','.','.','5'}
    //    ,{'.','.','.','.','8','.','.','7','9'}};
    //
    //bool r = isValidSudoku((char**)board, 9, 9);
    //
    //printf("output: %d;\n", r);
    printf("output: Segmentation fault;\n");
}

// Result 
//
// 2022/11/16
//      
//      