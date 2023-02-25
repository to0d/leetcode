#include <lt_help/lt.h>

class Solution {
public:
    string removeDuplicates(string s) {
        static char buf[100000];
        int buf_len = 0, len = s.length();
        for(int i = 0; i < len ;++i)
        {   char c = s.at(i);
            if( buf_len == 0 || buf[buf_len-1] != c )
                buf[buf_len++] = c;
            else
                --buf_len;
        }
        return string(buf, buf_len);
    }
};



void test(string s)
{
    cout << "input: " << s;
    string r = Solution().removeDuplicates(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("abbaca");
}


// Result 
//
// 2022-12-08: Runtime 54ms 21.64% Memory 10.5MB 81.62%, https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/856646418/
// 2023-02-24: Runtime 15ms 87.50% Memory 10.5MB 82.14%, https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/904201131/



