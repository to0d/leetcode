#include <lt_help/lt.h>



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(); 
        
        for(int j = 1; j < size; ++j)
            triangle[j][0] += triangle[j-1][0];  
        
        for(int i = 1; i < size; ++i)
            triangle[i][i] += triangle[i-1][i-1];      
        
        for(int i = 2; i < size; ++i)
            for(int j = i-1; j >= 1; --j)
                triangle[i][j] += std::min(triangle[i-1][j], triangle[i-1][j-1]);
        
        int rst = INT_MAX;
        for(int i = 0; i < size; ++i)
            rst = std::min(rst, triangle[size-1][i]);
        
        return rst;
    }
};


void test(vector<vector<int>> triangle)
{
    cout << "input: ";
    outputVector(triangle);
    int r = Solution().minimumTotal(triangle);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{2},{3,4},{6,5,7},{4,1,8,3}});
}


// Result 
//
// 2022-12-05: Runtime 0ms 100% Memory 8.6MB 95.4%, https://leetcode.com/problems/triangle/submissions/855050096/


