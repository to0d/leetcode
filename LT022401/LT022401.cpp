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
        static char buf[300001];
        int buf_len = 0, s_len  = s.length();
        vector<int> op_stack, bracket_index_stack;
        vector<char> bracket_prev_stack;
        
        // step1: remove_stack:  1-(2-(3-4)) -> 1-(2-3+4) -> 1-2+3-4
        int bracket_index = 0, op_indx = 0, val_num = 0;
        char prev_op = 0;
        for(int i = 0; i < s_len; ++i )
        {   char c = s.at(i);
            switch( c )
            {   case '(':                    
                    bracket_index_stack.push_back(buf_len);
                    bracket_prev_stack.push_back(prev_op);
                    buf[buf_len++] = ' ';
                    val_num = 0;
                    prev_op = c;
                    break;
                case ')':
                    prev_op = bracket_prev_stack.back();  bracket_prev_stack.pop_back();            // pop previous op before '('                 
                    bracket_index = bracket_index_stack.back(); bracket_index_stack.pop_back();     // pop index of '('
                    if( prev_op == '-' )
                    {   for(auto it = op_stack.rbegin(); it != op_stack.rend() && (op_indx = *it) > bracket_index; ++it)
                            buf[op_indx] = buf[op_indx] == '+' ? '-' : '+';         // '-(1-2)' => '1-1+2'
                    }
                    buf[buf_len++] = ' ';
                    prev_op = c;
                    break;
                case '+':
                case '-': 
                    if( val_num == 0 )          // special case: '( - 1)' ==> '(0 - 1)'
                        buf[buf_len++] = '0';
                    op_stack.push_back(buf_len);
                    buf[buf_len++] = c;
                    prev_op = c;
                    break;
                case ' ': 
                    break;               
                default :                 
                    buf[buf_len++] = c;
                    ++val_num;
            }
        }        
        buf[buf_len] = '\0';
        
        // step2: calculate simple expression: '1 - 2 + 3'
        return cal(buf);
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
    test("1 + 1");
    test("1-(     -2)");
    test("(3-(2-(5-(9-(4)))))");
}

// Result 
//
// 2023-07-30: Runtime 40ms 14.28% Memory 9.06MB 37.52%, https://leetcode.cn/problems/basic-calculator/submissions/451513653/



