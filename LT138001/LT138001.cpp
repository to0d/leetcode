#include <lt_help/lt.h>

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        
        vector<int> minColumnIdx;
        for(int i = 0; i < row; ++i)
        {   int minIdx = 0, minVal = matrix[i][0];  
            for(int j = 0; j < column; ++j)
            {   int val = matrix[i][j];
                if( val < minVal )
                {   minIdx = j;
                    minVal = val;
                }
            }
            minColumnIdx.push_back(minIdx);
        }
        
        vector<int> maxRowIdx;
        for(int j = 0; j < column; ++j)
        {   int maxIdx = 0, maxVal = matrix[0][j];  
            for(int i = 0; i < row; ++i)
            {   int val = matrix[i][j];
                if( val > maxVal )
                {   maxIdx = i;
                    maxVal = val;
                }
            }
            maxRowIdx.push_back(maxIdx);
        }

        vector<int> rst;
        for(int i = 0; i < row; ++i)
        {   int minIdx = minColumnIdx[i];
            if( maxRowIdx[minIdx] == i )
                rst.push_back(matrix[i][minIdx]);
        }

        return rst;
    }
};



void test(vector<vector<int>> matrix)
{
    cout << "input: ";
    outputVector(matrix);
    vector<int> r = Solution().luckyNumbers(matrix);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({{3,7,8},{9,11,13},{15,16,17}});
}


// Result 
//
// 2022-12-13: Runtime 34ms 18.99% Memory 11.6MB 50.57%, https://leetcode.com/problems/lucky-numbers-in-a-matrix/submissions/859200710/
// 2023-02-25: Runtime 23ms 71.27% Memory 11.6MB 48.98%, https://leetcode.com/problems/lucky-numbers-in-a-matrix/submissions/904213278/



