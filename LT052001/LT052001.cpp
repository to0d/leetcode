#include <lt_help/lt.h>

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length(), firstNotCapital = -1;
        if( len == 0 )  return false;
        if( len == 1 )  return true;
        
        for(int i = 0; firstNotCapital == -1 && i < len; ++i)
        {   char c = word.at(i);
            if( !isCapital(c) )
                firstNotCapital = i;
        }
        
        if( firstNotCapital == -1 ) // all characters are capital
            return true;

        if( firstNotCapital == 0 || firstNotCapital == 1 ) // first or second character is not capital
        {   for(int i = firstNotCapital+1; i < len; ++i)
            {   char c = word.at(i);
                if( isCapital(c) )
                    return false;
            }
            return true;
        }

        return false;
    }
    
    bool isCapital(char c){   
        return c >= 'A' && c <= 'Z';
    }
};



void test(string word)
{
    cout << "input: " << word << "; output: ";
    bool r = Solution().detectCapitalUse(word);
    cout << r << ";" << endl;
}

int main(void)
{
    test("USA");
}

// Result 
//
// 2022-11-19: Runtime 4ms 28.55% Memory 5.5MB 87.82%, https://leetcode.com/problems/detect-capital/submissions/846389174/
// 2023-02-24: Runtime 0ms 100% Memory 6.1MB 73.20%, https://leetcode.com/problems/detect-capital/submissions/904155614/



