#include <lt_help/lt.h>



class Solution {
public:
    string reverseVowels(string s) {
        int i = 0; 
        int j = s.size() - 1 ;
        while( i < j )
        {
            while( i < j && !isVowel(s[i]))
                ++i;
            while( i < j && !isVowel(s[j]))
                --j;
            
            if( i < j )
            {
                char c = s[j];
                s[j] = s[i];
                s[i] = c;
                ++i;
                --j;
            }
        }
        
        return s;
    }
    
    bool isVowel(char c)
    {
         static char vchar [256] = {0};
         static bool init = false;
         if( !init )
         {
             vchar['a'] = true;
             vchar['e'] = true;
             vchar['i'] = true;
             vchar['o'] = true;
             vchar['u'] = true;
             vchar['A'] = true;
             vchar['E'] = true;
             vchar['I'] = true;
             vchar['O'] = true;
             vchar['U'] = true;
             init =  true;
         }
         return vchar[c];
    }
};
    


void test(string s)
{
    cout << "input: " << s;
    string r = Solution().reverseVowels(s); 
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("hello");
    test("leetcode");
}

// Result 
//
// 2022-11-22: Runtime 3ms 96.98% Memory 7.7MB 87.91%, https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/847770424/

