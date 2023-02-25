#include <lt_help/lt.h>

char opStack[1024];
int  valStack[1024];
int opSize, valSize;

void init_stack() { opSize = 0; valSize = 0; }
void push_val(int val) { valStack[valSize++] = val; }
int pop_val()  { return valStack[--valSize]; }
int top_val()  { return valSize > 0 ? valStack[valSize-1] : 0; }
void push_op(char op) { opStack[opSize++] = op;  }
char pop_op()  { return opStack[--opSize]; }
bool empty_op(){ return opSize <= 0; }
char top_op()  { return opStack[opSize-1]; }

void cal(){
    char op = pop_op();
    int b = pop_val();
    int a = pop_val();
    //printf("cal %d %c %d\n", a, op, b);
    switch(op)
    {   case '+':  a += b; break;
        case '-':  a -= b; break;
        case '*':  a *= b; break;
        case '/':  a /= b; break;
    }
    push_val(a);
}

int calculate(char* s) {
    
    if( s == NULL ) return 0;
    
    init_stack();
    
    int val = 0;
    int vn = 0;
    char c;
    
    while( (c=*s)!='\0' || vn > 0 )
    {   //printf("while: c=%c\n", c);
        if( c != '\0' )
        {   s++;    
            if( c <= '9' && c >= '0' )
            {   val *= 10;
                val += c - '0';
                vn ++;
                continue;
            }
        }
        
        if( vn > 0 )
        {   push_val(val);
            val = 0;
            vn = 0;
        }
        
        switch(c)
        {
        case '+':
        case '-':
            while( !empty_op() )
                cal();
            if( c != '\0')
                push_op(c);
            break;
        case '*':
        case '/':
            if( !empty_op() && (top_op() == '*' || top_op() == '/') )
                cal();
            push_op(c);
            break;
        default: 
            break; /* ignore other char, including ' '*/
        }
    }
    
    while( !empty_op() )
        cal();
    
    return top_val();
}


void test(const char* s)
{
    printf("input: %s", s); 
    int r = calculate(makeString(s));
    printf("; output: %d\n", r);
}

int main(void)
{
    test("3+2*2");
    test(" 3/2 ");
    test(" 3+5 / 2 ");
}

// Result 
//
// 2022-11-19: Runtime 8ms 50% Memory 6.8MB 100%, https://leetcode.com/problems/basic-calculator-ii/submissions/846325586/
