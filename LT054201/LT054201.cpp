#include <lt_help/lt.h>

static const int rIdx[4] = {0, 0, 1, -1};
static const int cIdx[4] = {1, -1, 0, 0};

int getRowIndex(int r, int idx){   
    return r + rIdx[idx];
}

int getColumnIndex(int c, int idx) {  
    return c + cIdx[idx];
}

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m_row = mat.size();
        m_column = mat[0].size();
        vector<vector<int>> rst;
        for(int i = 0; i < m_row; ++i)
        {   vector<int> x;
            for(int j = 0; j < m_column; ++j)
                x.push_back(-1);
            rst.push_back(x);
        }
        
        queue<int> rowQueue, columnQueue;
        for(int i = 0; i < m_row; ++i)
            for(int j = 0; j < m_column; ++j)
                if( mat[i][j] == 0 )
                {   rst[i][j] = 0;
                    for(int k = 0; k < 4; ++k)
                    {   rowQueue.push(getRowIndex(i, k)); 
                        columnQueue.push(getColumnIndex(j, k));
                    }
                }

        while( !rowQueue.empty() )
        {   int i = rowQueue.front(); rowQueue.pop();
            int j = columnQueue.front(); columnQueue.pop();
            if( i < 0 || i >= m_row || j < 0 || j >= m_column )
                continue;
            int cur = rst[i][j];
            if( cur == 0 )
                continue;

            int minVal = -1;
            for(int k = 0; k < 4; ++k)
            {   int val = _get(rst, getRowIndex(i, k), getColumnIndex(j, k));
                if( val != -1 )
                {   if( minVal == -1 )
                        minVal = val;
                    else
                        minVal = std::min(minVal, val);
                }
            }

            if( minVal == -1 )
                continue;
            
            if( cur != -1 && cur <= (minVal + 1) )
                continue;

            rst[i][j] = minVal + 1;
            for(int k = 0; k < 4; ++k)
            {   rowQueue.push(getRowIndex(i, k)); 
                columnQueue.push(getColumnIndex(j, k));
            }
        }

        return rst;
    }
    
    int _get(vector<vector<int>>& arr, int i, int j){   
        if( i < 0 || i >= m_row || j < 0 || j >= m_column)
            return -1;
        return arr[i][j];
    }

    int m_row;
    int m_column;
};



void test(vector<vector<int>> mat)
{
    cout << "input: ";
    outputVector(mat);
    vector<vector<int>> r = Solution().updateMatrix(mat);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test({{0,0,0},{0,1,0},{0,0,0}});
}

// Result 
//
// 2023-01-15: Runtime 160ms 20% Memory 43.5MB 10.48%, https://leetcode.com/problems/01-matrix/submissions/878470449/
// 2023-02-25: Runtime 160ms 16.89% Memory 43.4MB 10.37%, https://leetcode.com/problems/01-matrix/submissions/904438299/



