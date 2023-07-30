#include <lt_help/lt.h>

int op_level(char c){
    switch(c)
    {   case '+':
        case '-': return 10;
        case '*':
        case '/': return 20;
    }
    return 0;
} 

int cal(const char* s) {
    static char op_stack[4]; 
    static int  val_stack[4];
    int op_size = 0, val_size = 0, val = 0, vn = 0;
    char c;
    while( ( c=*s ) != '\0' || vn > 0 || op_size > 0 )
    {   if( c != '\0' )
        {   s++;    
            if( c <= '9' && c >= '0' )
            {   val *= 10;
                val += c - '0';
                vn ++;
                continue;
            }
            if( c == ' ' )
                continue;
        }

        if( vn > 0 )
        {   val_stack[val_size++] = val;    // push val
            val = 0;
            vn = 0;
        }
        
        int level = op_level(c);
        while( op_size > 0 && level <= op_level(op_stack[op_size-1]) )
        {   char op = op_stack[--op_size];
            int b = val_stack[--val_size], a = val_stack[--val_size];   // pop val
            switch(op)
            {   case '+':  a += b; break;
                case '-':  a -= b; break;
                case '*':  a *= b; break;
                case '/':  a /= b; break;
            }
            val_stack[val_size++] = a;      // push val
        }
        
        if( level > 0 )
            op_stack[op_size++] = c;        // push op
    }

    return val_size > 0 ? val_stack[val_size-1] : 0; // Top val
}

class Solution {
public:
    int calculate(string s) {
        return cal(s.c_str());
    }
};


void test(string s)
{
    cout << "input: " << s;
    int r = Solution().calculate(s);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("3+2*2");
    test(" 3/2 ");
    test(" 3+5 / 2 ");
}

// Result 
//
// 2022-11-19: Runtime 32ms 41.15% Memory 8.4MB 100%, https://leetcode.com/problems/basic-calculator-ii/submissions/846323854/
// 2023-02-20: Runtime 86ms 12.28% Memory 10.6MB 71.43%, https://leetcode.com/problems/basic-calculator-ii/submissions/901594075/
// 2023-07-30: Runtime 16ms 74.27% Memory 8.95MB 99.85%, https://leetcode.cn/problems/basic-calculator-ii/submissions/451505063/



