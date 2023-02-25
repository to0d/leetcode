#include <lt_help/lt.h>


// **Deduce:**
//
//	S(n) = S(n-1)*Y(n) + S(n-2)*Y(n-1,n)
//	S(0) = 1	
//   S(1) = 1
//   	Y(n) = 1  when char in string(n) is '1', '2', ...'9'
//              0  others
//   Y(n-1,n) = 1  when two-char in string(n-1) and string(n) is '10','11'..'26'
//              0  others

class Solution {
public:
    int numDecodings(string s) {
        if( s.empty() ) 
            return 0;
        if( s.size() == 1 ) 
            return canDecode(s.at(0)) ? 1 : 0;
        
        char c1(s.at(0)),c2;
        int s0(1), s1, s2;

        s1 = canDecode(c1) ? 1 : 0;
        for( size_t i = 1; i < s.size(); ++i, s0=s1, s1=s2, c1=c2)
        {   c2 = s.at(i);
            s2  = canDecode(c2)? s1 : 0;
            s2 += canDecode(c1,c2)? s0 : 0;
        }

        return s2;
    }
    
    bool canDecode(char c){ 
        return c >= '1' && c <= '9'; 
    }

    bool canDecode( char c1 , char c2) {   
        return c2 >= '0' && ((c1 == '1' && c2 <= '9')||(c1 == '2' && c2 <= '6'));
    }
};



void test(string s)
{
    cout << "input: " << s;
    int r = Solution().numDecodings(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("12");
    test("226");
    test("06");
}

// Result 
//
// 2022-11-16: Runtime 4ms 43.49% Memory 6.2MB 78.56%, https://leetcode.com/problems/decode-ways/submissions/844609447/
// 2023-02-18: Runtime 4ms 43% Memory 6.2MB 51.94%, https://leetcode.com/problems/decode-ways/submissions/900103891/


