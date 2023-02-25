#include <lt_help/lt.h>

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size(), count = 0;
        for(int i = 0, len = column; i < row; ++i)
        {   vector<int>& vec = grid[i];
            if( vec[0] < 0)
            {   count += (row - i)*column;
                break;
            }
            int pos = firstNegative(vec, len);
            count += column - pos;
            len = (pos < column ? pos + 1 : pos);
        }

        return count;
    }

    int firstNegative(vector<int>& vec, int len){   
        int low = 0, high = len-1;
        while( low <= high )
        {   int m = ( high + low ) / 2;
            int v = vec[m];
            if( v == 0 )
            {   while(m < len && vec[m] == 0 )
                    ++m;                
                return m;
            }
            if( v > 0 )
                low = m + 1;
            else
                high = m - 1;
        }
        return low;
    }
};




void test(vector<vector<int>> grid)
{
    cout << "input: ";
    outputVector(grid);
    int r = Solution().countNegatives(grid);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}});
}


// Result 
//
// 2022-12-13: Runtime 29ms 12.22% Memory 10.5MB 55.42%, https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/858930568/
// 2023-02-24: Runtime 14ms 87.14% Memory 10.6MB 13.11%, https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/904209989/



