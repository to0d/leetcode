#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size(), column = mat[0].size();
        if( row == r || row*column != r*c)
            return mat;
        vector<vector<int>> rst;
        vector<int> line;
        for(int i = 0; i < row; ++i)
        {   vector<int>& data = mat[i];
            for(int j = 0; j < column; ++j)
            {   line.push_back(data[j]);
                if( line.size() == c )
                {   rst.push_back(line);
                    line.clear();
                }
            }
        }
        return rst;
    }
};



void test(vector<vector<int>> mat, int r, int c)
{
    cout << "input: r=" << r << ", c=" << c << ", mat=";
    outputVector(mat);
    vector<vector<int>> rr = Solution().matrixReshape(mat, r, c);
    cout << "; output: ";
    outputVector(rr);
    cout << ";" << endl;
}

int main(void)
{   
    test({{1,2},{3,4}}, 1, 4);
}


// Result 
//
// 2023-01-09: Runtime 8ms 87.37% Memory 10.8MB 46.14%, https://leetcode.com/problems/reshape-the-matrix/submissions/874815235/


