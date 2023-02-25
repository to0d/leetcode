#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> rst;
        for(int i = 0; i < column; ++i)
        {   rst.push_back({});
            vector<int>& vec = rst[i];
            for(int j = 0; j < row; ++j)
                vec.push_back(matrix[j][i]);
        }
        return rst;
    }
};



void test(vector<vector<int>> matrix)
{
    cout << "input: ";
    outputVector(matrix);
    vector<vector<int>> r = Solution().transpose(matrix);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({{1,2,3},{4,5,6}});
}


// Result 
//
// 2022-12-06: Runtime 33ms 5.97% Memory 10.5MB 94.69%, https://leetcode.com/problems/transpose-matrix/submissions/855594696/
// 2023-02-24: Runtime 11ms 85.47% Memory 10.6MB 80.12%, https://leetcode.com/problems/transpose-matrix/submissions/904196945/



