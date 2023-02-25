#include <lt_help/lt.h>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        
        while (len > 0 && s.at(len-1) == ' ')   // skip tail blank
            --len;

        int pos = len-1;
        while( pos >= 0 && s.at(pos) != ' ')
            --pos;
        
        return len - pos - 1;
    }
};



void test(string s)
{
    cout << "input: " << s ;
    int r = Solution().lengthOfLastWord(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("Hello World"); 
}


// Result 
//
// 2022-11-23: Runtime 0ms 100% Memory 6.5MB 56.41%, https://leetcode.com/problems/length-of-last-word/submissions/848333258/
// 2023-02-17: Runtime 0ms 100% Memory 6.5MB 56.59%, https://leetcode.com/problems/length-of-last-word/submissions/899827461/

