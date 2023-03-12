#include <lt_help/lt.h>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), column = matrix[0].size(), maxi=0;
        vector<int> dp( (row+1)*(column+1),0 );
#define dpf(i, j) dp[(i)*(column+1) + (j)]
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= column; j++)
                if ( matrix[i-1][j-1] == '1')
                {   dpf(i, j) = min(min(dpf(i, j-1), dpf(i-1, j)), dpf(i-1,j-1)) + 1;
                    maxi = max(maxi, dpf(i, j));
                }
        return maxi*maxi;
    }
};



void test(vector<vector<char>> matrix)
{
    cout << "input: ";
    outputVector(matrix);
    int r = Solution().maximalSquare(matrix);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{'0','1'},{'1','0'}});
}


// Result 
//
// 2023-03-12: Runtime 92ms 63.51% Memory 20.6MB 78.22%, https://leetcode.com/problems/maximal-square/submissions/913848366/, https://leetcode.com/problems/maximal-square/solutions/3225158/solution-in-c/

