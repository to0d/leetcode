#include <lt_help/lt.h>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), column = board[0].size();        
        if( word.length() > row*column)
            return false;
        static int used[100];
        memset( used, 0, 100* sizeof(int) );
        const char* p = word.c_str();
        char c = *p;
        for(int i = 0; i < row; ++i )
        {   for(int j = 0; j < column; ++j )
            {   if( board[i][j] == c )
                {   used[i*column+j] = 1;
                    if(_exist(board,row,column,p,used,i,j,1))
                        return true;  
                    used[i*column+j] = 0;
                }
            }
        }
        return false;
    }
    
    bool _exist(vector<vector<char>>& board, int r, int c, const char* word, int* used, int i, int j, int k) {       
        static int add[4] = {1, 0, -1, 0};        
        char ch = word[k];
        if( ch == '\0')
            return true;
        for(int a = 0; a < 4; ++a )
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
};

void test(vector<vector<char>> board, string word)
{
    cout << "input: word=" << word << ", board=";
    outputVector(board);
    bool r = Solution().exist(board, word);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED");
}


// Result 
//
// 2023-01-04: Runtime 277ms 95.98% Memory 8.1MB 23.88%, https://leetcode.com/problems/word-search/submissions/871211848/



