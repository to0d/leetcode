#include <lt_help/lt.h>

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        if( size <= 1 )
            return false;
        
        char c = s.at(0);       
        for(int i = 1; i <= size/2; ++i)
        {   if( s.at(i) != c || (size % i) != 0 )
                continue;
            int subSize = i, subCount = size/i, find = -1;
            for(int j = 0; find == -1 && j < subSize;++j)
                for(int k = 1; find == -1 && k < subCount;++k)
                    if (s.at(j) != s.at(j+k*subSize))
                        find = k;
            if( find == -1)
                return true;
        }

        return false;
    }
};



void test(string s)
{
    cout << "input: " << s << "; output: ";
    bool r = Solution().repeatedSubstringPattern(s);
    cout << r << ";" << endl;
}

int main(void)
{
    test("abab");
}

// Result 
//
// 2022-11-25: Runtime 99ms 27.21% Memory 9.4MB 94.39%, https://leetcode.com/problems/repeated-substring-pattern/submissions/849528528/
// 2023-02-24: Runtime 24ms 58.7% Memory 9.4MB 95.30%, https://leetcode.com/problems/repeated-substring-pattern/submissions/904147337/



