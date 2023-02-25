#include <lt_help/lt.h>

class Solution {
public:
    bool validPalindrome(string s) {        
        int dc = 0;                
        for(const char *p = s.c_str(), *q = s.c_str() + s.length() - 1 ; p < q ; ++p, --q )
        {   if(*p == *q)
                continue;
            
            if( dc > 0 )
                return false;
            
            if( (p+1) == q )
                return dc == 0;
            
            if( *(p+1) == *q )
                if(_validPalindrome(p+1, q))
                   return true;
            
            if( *p == *(q-1) )
                if(_validPalindrome(p, q-1))
                   return true;
            
            return false;
        }
        
        return true;
    }
    
    bool _validPalindrome(const char* p, const char* q){   
        for( ; p < q ; ++p, --q )
            if(*p != *q)
                return false;
        return true;
    }
};



void test(string s)
{
    cout << "input: " << s;
    bool r = Solution().validPalindrome(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test("abca");
}


// Result 
//
// 2022-12-01: Runtime 223ms 5.9% Memory 19.6MB 91.36%, https://leetcode.com/problems/valid-palindrome-ii/submissions/852618345/
// 2023-02-24: Runtime 46ms 94.82% Memory 19.7MB 64.12%, https://leetcode.com/problems/valid-palindrome-ii/submissions/904187399/


