#include <lt_help/lt.h>

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int dx1 = points[1][0] - points[0][0];
        int dx2 = points[2][0] - points[1][0];
        int dy1 = points[1][1] - points[0][1];
        int dy2 = points[2][1] - points[1][1];
        return dx2*dy1 != dx1*dy2;
    }
};



void test(vector<vector<int>> points)
{
    cout << "input: ";
    outputVector(points);
    bool r = Solution().isBoomerang(points);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{1,1},{2,3},{3,2}});
}


// Result 
//
// 2022-12-08: Runtime 9ms 15.87% Memory 10.2MB 98.47%, https://leetcode.com/problems/valid-boomerang/submissions/858410250/
// 2023-02-25: Runtime 4ms 55.99% Memory 10.4MB 60.47%, https://leetcode.com/problems/valid-boomerang/submissions/904427103/



