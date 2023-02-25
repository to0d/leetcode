#include <lt_help/lt.h>




class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size(), column = mat[0].size();
        vector<int> rst;
        int r = 0, c = 0, count = 0, max_count = row*column;
        bool up = true;
        while( count++ < max_count )
        {   rst.push_back(mat[r][c]);
            if( up )
            {   if( r == 0 )
                {   if( c == (column-1) )
                        r++;
                    else
                        c++;
                    up = false;
                }
                else
                {   
                    if( c == (column-1) )
                    {   r++;
                        up = false;
                    }
                    else
                    {   r--;
                        c++;
                    }
                }
            }
            else
            {   if( r == (row-1) )
                {   c++;
                    up = true;
                }
                else
                {   r++;
                    if( c == 0 )
                        up = true;
                    else
                        c--;
                }
            }
        }
        return rst;
    }
};


void test(vector<vector<int>> mat)
{
    cout << "input: ";
    outputVector(mat);
    vector<int> r = Solution().findDiagonalOrder(mat);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test({{1,2,3},{4,5,6},{7,8,9}});
}

// Result 
//
// 2023-01-15: Runtime 23ms 97.70% Memory 18.4MB 48.8%, https://leetcode.com/problems/diagonal-traverse/submissions/878425303/


