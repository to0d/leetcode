#include <lt_help/lt.h>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n1 = ( n + 1 ) / 2;
        int n2 = n / 2;
        for( int i = 0; i < n1; ++i)
        {   for( int j = 0 ; j < n2 ; ++j )
            {   int t = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
        }
    }
};



void test(vector<vector<int>> matrix)
{
    cout << "input: ";
    outputVector(matrix); 
    Solution().rotate(matrix);
    cout << "; output: "; 
    outputVector(matrix);
    cout << ";" << endl;
}

int main(void)
{
    test({{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}});
}

// Result 
//
// 2022-11-16: Runtime 3ms 48.2% Memory 7.2MB 41.3%, https://leetcode.com/problems/rotate-image/submissions/844603344/
// 2023-02-17: Runtime 2ms 58.16% Memory 7.1MB 41.32%, https://leetcode.com/problems/rotate-image/submissions/899809735/

