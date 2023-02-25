#include <lt_help/lt.h>




class Solution {
public:
    int titleToNumber(string s) {
     
        int v = 0;
        for( auto c : s )
        {
            v*= 26;
            v+= c - 'A' + 1;
        }
        
        return v;
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
