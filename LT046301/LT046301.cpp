#include <lt_help/lt.h>

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();        
        int cell_count = 0, border_count = 0;

        for(int i=0; i<row; ++i )
            for(int j=0; j<column; ++j )
            {   int v = grid[i][j];
                if( v ==0 )
                    continue;
                ++cell_count;
                if( i > 0 && grid[i-1][j] == 1)
                    ++border_count;
                if( j > 0 && grid[i][j-1] == 1)
                    ++border_count;
            }

        return cell_count*4-border_count*2;
    }
};



void test(vector<vector<int>> grid)
{
    cout << "input: ";
    outputVector(grid);
    int r = Solution().islandPerimeter(grid);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}}); 
}


// Result 
//
// 2022-11-30: Runtime 208ms 17.19% Memory 96.2MB 87.81%, https://leetcode.com/problems/island-perimeter/submissions/852053216/
// 2023-02-24: Runtime 107ms 92.12% Memory 96.1MB 98.98%, https://leetcode.com/problems/island-perimeter/submissions/904148044/



