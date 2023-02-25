#include <lt_help/lt.h>

class Solution {
public:
#define MAX_BUF_LEN 10
    string convertToTitle(int n) {
        static char buf[MAX_BUF_LEN];
        int len = 0;
        for(; n > 0; n = (n - 1)/26)
            buf[MAX_BUF_LEN - (len++) - 1] = 'A' + (n-1)%26;
        return string(buf+MAX_BUF_LEN-len, buf+MAX_BUF_LEN);
    }
};

  
   
void test(int n)
{
    cout << "input: " << n;
    string r = Solution().convertToTitle(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(1);
    test(28);
}

// Result 
//
// 2022-11-21: Runtime 0ms 100% Memory 6MB 52.92%, https://leetcode.com/problems/excel-sheet-column-title/submissions/847488776/
// 2023-02-20: Runtime 0ms 100% Memory 6MB 8.23%, https://leetcode.com/problems/excel-sheet-column-title/submissions/901600979/
