#include <lt_help/lt.h>


class Solution {
public:
    int titleToNumber(string columnTitle) {
        int val = 0;
        for(char c : columnTitle)
            val = val*26 + (int)(c - 'A') + 1;
        return val;
    }
};


void test(string s)
{
    cout << "input: " << s;
    int r = Solution().titleToNumber(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("A");
    test("AB");
}

// Result 
//
// 2022-11-21: Runtime 3ms 58.89% Memory 6MB 72%, https://leetcode.com/problems/excel-sheet-column-number/submissions/847495718/
// 2023-07-26: Runtime 0ms 100% Memory 5.65MB 66.72%, https://leetcode.cn/problems/excel-sheet-column-number/submissions/450339235/
