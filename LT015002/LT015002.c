#include <lt_help/lt.h>

int evalRPN(char** tokens, int size) {
    
    if( tokens == NULL || size == 0 )
        return 0;
    
    int *stack = (int*) malloc(size*sizeof(int));
    int slen, i, a, b;
    char c;
    
    for( i=0, slen = 0; i < size; ++i )
    {
        c=tokens[i][0];
        if( (tokens[i][1] != '\0')||( c != '+' && c != '-' && c != '*' && c != '/' ))
        {   a = atoi(tokens[i]);
        }
        else
        {
            b = stack[--slen];
            a = stack[--slen];
            switch( c )
            {   case '+': a += b; break;
                case '-': a -= b; break;
                case '*': a *= b; break;
                case '/': a /= b; break;
            }
        }
        stack[slen++] = a;
    }
    
    a = slen >0? stack[slen-1] : 0;
    free(stack);
    return a;
}


void test(char** tokens, int size)
{
    printf("input: ");
    outputArray4(tokens, size);
    int r = evalRPN(tokens, size);
    printf("; output: %d\n;", r);
}

int main(void)
{
    char* tokens[5] = {"2","1","+","3","*"};
    test(tokens, 5);
}

// Result 
//
// 2022/11/21
//      Runtime Error
//      ["-128","-128","*","-128","*","-128","*","8","*","-1","*"]