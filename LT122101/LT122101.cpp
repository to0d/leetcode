#include <lt_help/lt.h>

class Solution {
public:
    int balancedStringSplit(string s) {
        int len = s.length(), count = 0;
        for(int i = 0, last = 0, val = 0; i < len; ++i)
        {   char c = s.at(i);
            val += (c == 'L' ? 1 : -1);
            if( val == 0 )
            {   last = i + 1;
                ++count;
            }
        }

        return count;
    }
};



void test(string s)
{
    cout << "input: " << s;
    int r = Solution().balancedStringSplit(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("RLRRLLRLRL");
}


// Result 
//
// 2022-12-12: Runtime 3ms 43.60% Memory 6.3MB 52.4%, https://leetcode.com/problems/split-a-string-in-balanced-strings/submissions/858407686/
// 2023-02-24: Runtime 0ms 100% Memory 6.2MB 51.97%, https://leetcode.com/problems/split-a-string-in-balanced-strings/submissions/904205457/


