#include <lt_help/lt.h>

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = (ax2-ax1)*(ay2-ay1);
        int areaB = (bx2-bx1)*(by2-by1);
        int areaC = 0;
        int l = std::max(ax1,bx1); 
        int r = std::min(ax2,bx2); 
        int t = std::min(ay2,by2);
        int b = std::max(ay1,by1);

        if( r > l && t > b )
            areaC = (r-l)*(t-b);    
        
        return areaA+areaB-areaC;
    }
};


void test(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    printf("input: [%d %d %d %d %d %d %d %d]", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    int r = Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test(-3, 0, 3, 4, 0, -1, 9, 2);
}

// Result 
//
// 2022-11-01: Runtime 18ms 6.38% Memory 5.6MB 42.55%, https://leetcode.com/problems/rectangle-area/submissions/848495985/
// 2023-02-18: Runtime 4ms 87.47% Memory 6MB 10.69%, https://leetcode.com/problems/rectangle-area/submissions/900111090/
