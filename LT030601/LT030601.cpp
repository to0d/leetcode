#include <lt_help/lt.h>

// xxxxxxxxxxxxxxxxxxxxxxxxxxxx 
// |<-a->|<-b->|<-c->|    
// |<--          len       -->|
//  num[0..a-1] + num[a..a+b-1] = [a+b..a+b+c-1]
//     a+b+c <= len
//     a < c
//     b < c  ==> b <= (len - a) /2, a <= len/2
class Solution {
public:
    bool isAdditiveNumber(string num) {
        const char *pa = num.c_str();
        int len = num.size();
        for(int la = len /2; la > 0; --la )
            for(int lb = ( len - la) / 2; lb > 0; --lb)
                if( dfs( pa, la, lb , len))
                    return true;
        
        return false;
    }
    
    bool dfs( const char* pa, int la, int lb, int len){
        static char tmp[256] = {0};
        if( lb > ( len - la )/2 || (*(pa + la) == '0' && lb > 1) ) 
            return false;
        
        const char* pb = pa + la;
        char* pt = tmp + sizeof( tmp) / sizeof(char) - 2;
        int lc(0), v(0);
        for (int i = 0; i < la || i < lb || v != 0; v /= 10, ++i, ++lc, --pt)
        {   if( i < la ) 
                v += *( pa + la - i - 1) - '0';
            if( i < lb ) 
                v += *( pb + lb - i - 1) - '0';
            *pt = '0' + v % 10;
        }
        
        // overflow
        if( (la + lb + lc) > len ) 
           return false;
       
        ++pt;     
        const char* pc = pa + la + lb;
        for(int i = lc; i > 0; --i,++pc, ++pt)
            if( *pc != *pt)
                return false;

        return (la + lb + lc) == len || dfs( pa+la, lb, lc, len - la );
    }
};
    


void test(string num)
{
    cout << "input: " << num;
    bool r = Solution().isAdditiveNumber(num); 
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("112358");
    test("199100199");
}

// Result 
//
// 2022-11-22: Runtime 0ms 100% Memory 5.9MB 96.37%, https://leetcode.com/problems/additive-number/submissions/847767775/
// 2023-02-22: Runtime 0ms 100% Memory 5.9MB 95.54%, https://leetcode.com/problems/additive-number/submissions/902741207/

