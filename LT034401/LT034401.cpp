#include <lt_help/lt.h>

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, h = s.size() - 1;
        for( ; l < h; ++l, --h )
        {   char c = s[l];
            s[l] = s[h];
            s[h] = c;
        }
    }
};



void test(vector<char> s)
{
    cout << "input: ";
    outputVector(s);
    cout << "; output: "; 
    Solution().reverseString(s);
    outputVector(s);
    cout << endl;
}


int main(void)
{ 
    test({'h','e','l','l','o'});
}

// Result 
//
// 2022-11-21: Runtime 35ms 17.74% Memory 23.2MB 50.67%, https://leetcode.com/problems/reverse-string/submissions/847195926/
// 2023-02-22: Runtime 19ms 85.90% Memory 23.2MB 50.96%, https://leetcode.com/problems/reverse-string/submissions/902938969/


