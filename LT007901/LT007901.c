#include <lt_help/lt.h>

bool _exist(char** board, int r, int c, char* word, int* used, int i, int j, int k) {

    static int add[4] = {1, 0, -1, 0};    

    char ch = word[k];
    if( ch == '\0')
    {   return true;
    }
    
    for( int a = 0; a < 4; ++a )
    {   int ii = i + add[a];
        int jj = j + add[(a+1)%4];
        if( ii >= 0 && ii < r && jj >=0 && jj < c && used[ii*c+jj] == 0 && board[ii][jj] == ch )
        {   used[ii*c+jj] = 1;
            if(_exist(board,r,c,word,used,ii,jj,k+1))
                return true; 
            used[ii*c+jj] = 0;
        }
    }
    return false;
}

bool exist(char** board, int boardSize, int *boardColSize, char* word) {
    
    int c = *boardColSize;
    if( strlen(word) > boardSize*c )
        return false;
    
    int *used = (int*) malloc(boardSize*c*sizeof(int));
    memset( used, 0, boardSize*c*sizeof(int) );
    
    int i, j;
    char ch = word[0];
    
    for( i = 0; i < boardSize; ++i )
    {   for( j = 0; j < c; ++j )
        {   if( board[i][j] == ch )
            {   used[i*c+j] = 1;
                if(_exist(board,boardSize,c,word,used,i,j,1))
                    return true;  
                used[i*c+j] = 0;
            }
        }
    }
    free(used);
    return false;
}

            
void test(char** board, int boardSize, int *boardColSize, const char* word)
{
    printf("input: board=");
    outputArray3(board, boardSize, *boardColSize);
    printf(", word=%s", word);
    bool r = exist(board, boardSize, boardColSize, makeString(word));
    printf("; output: %d\n", r);
}

int main(void)
{
    char data[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    char* board[3] = {data[0], data[1], data[2]};
    int boardColSize = 4;
    test(board, 3, &boardColSize, "ABCCED");
}

// Result 
//
// 2022-11-19: Runtime 172ms 95.12% Memory 5.9MB 21.14%, https://leetcode.com/problems/word-search/submissions/846168477/

