#include <lt_help/lt.h>

bool isMatch2(const char* s, const char* p, int i, int j, int* matched, int row) {
    
    //printf("isMatch2: %s, %s\n", s+i, p+j);
    
    if( matched[i*row+j] == 1)
    {   return false;
    }
    
    matched[i*row+j] = 1;
    
    char c = *(p+j); 
    
    if( c == '\0' )
    {   return *(s+i) == '\0';
    }
        
MATCH: if( c == '*' )
    {
        char c2 = *(p+j+1);
        //printf("c2: %c\n", c2);
        
        if( c2 == '\0' )
            return true;
        
        if( c2 == '?' )
        {
            if( *(s+i) == '\0' )
                return false;
            else
            {   i++;
                j++;
                goto MATCH;
            }
        }
        
        if( c2 == '*' )
        {   j++;
            goto MATCH;
        }
    
        for( ; *(s+i) != '\0' ; ++i )
        {   if( *(s+i) == c2 && isMatch2(s, p,i+1,j+2, matched, row))
                return true;
        }
        
        return false;
    }
    
    if( *(s+i) == '\0' )
        return false;
    
    if( c == '?' )
        return isMatch2(s, p,i+1,j+1, matched, row);
    
    return c == *(s+i) && isMatch2(s,p,i+1,j+1, matched, row);
}

class Solution {
public:
    bool isMatch(string s, string p) {
    #define ROW   500
    #define COL   500
        static int matched[ROW*COL];
        memset(matched, 0, sizeof(matched));
        return isMatch2(s.c_str(), p.c_str(), 0, 0, matched, ROW);
    }
};


void test(string s, string p)
{
    cout << "input: s=" << s << ", p=" << p;
    bool r = Solution().isMatch(s, p);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
     test("aa", "a");
}

// Result 
//
// 2022/11/16
//    Runtime Error  
//      