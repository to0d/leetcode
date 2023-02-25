#include <lt_help/lt.h>

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if( size <= 2 ) 
            return true;        
        
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int dx1 = coordinates[1][0] - x0, dy1 = coordinates[1][1] - y0;
        
        for(int i = 2; i< size; ++i)
            if((coordinates[i][0] - x0)*dy1 != dx1*(coordinates[i][1] - y0))
                return false;
        
        return true;
    }
};



void test(vector<vector<int>> coordinates)
{
    cout << "input: ";
    outputVector(coordinates);
    bool r = Solution().checkStraightLine(coordinates);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}});
}


// Result 
//
// 2022-12-12: Runtime 22ms 8.93% Memory 10.2MB 47.35%, https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/858413089/
// 2023-02-24: Runtime 7ms 90.60% Memory 10MB 94.46%, https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/904206016/



