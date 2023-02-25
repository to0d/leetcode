#include <lt_help/lt.h>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), column = matrix[0].size();
        for(; k > 1; --k )
        {   int i = 0, j = 0, guard = INT_MAX;
            while( 1 )
            {   int nr = INT_MAX;
                if( i < row-1)
                    nr = matrix[i+1][j];
                
                int nc = INT_MAX;
                if( j < column-1)
                    nc = matrix[i][j+1];
                
                if( nr < nc )
                {   matrix[i][j] = matrix[i+1][j];
                    ++i;
                    continue;
                }
                
                if( nc < nr || (nc==nr && nc != INT_MAX) )
                {   matrix[i][j] = matrix[i][j+1];
                    ++j;
                    continue;
                }

                matrix[i][j] = guard;
                break;
            }
        }
        
        return matrix[0][0];
    }
};



void test(vector<vector<int>> matrix, int k)
{
    cout << "input: k=" << k << ", matrix=";
    outputVector(matrix);
    int r = Solution().kthSmallest(matrix, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test( {{1,5,9},{10,11,13},{12,13,15}}, 8);
}

// Result 
//
// 2022-11-22: Runtime 320ms 5.26% Memory 8.6MB 60.53%, https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/847772956/
// 2023-02-22: Runtime 544ms 5.11% Memory 13.1MB 95.46%, https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/902950208/

