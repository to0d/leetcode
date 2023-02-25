#include <lt_help/lt.h>

class Solution {
public:
    int countSegments(string s) {
        int count = 0, len = s.length(), last = -1;
        for (int i = 0; i < len; ++i )
        {   char c = s.at(i);
            if( c == ' ' )
            {   if( last != -1 )
                {   count++;
                    last = -1;
                }
            }
            else if( last == -1 )
                last = i;
        }
        
        if( last != -1 )
            count++;
        
        return count;
    }
};


void test(string s)
{
    cout << "input: " << s << "; output: ";
    int r = Solution().countSegments(s);
    cout << r << ";" << endl;
}

int main(void)
{
    test("Hello, my name is John");
}

// Result 
//
// 2022-11-25: Runtime 2ms 39.90% Memory 6MB 92.99%, https://leetcode.com/problems/number-of-segments-in-a-string/submissions/849506637/
// 2023-02-24: Runtime 0ms 100% Memory 6.1MB 93.8%, https://leetcode.com/problems/number-of-segments-in-a-string/submissions/904143293/

