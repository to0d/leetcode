#include <lt_help/lt.h>

char* simplifyPath(char* path) {
    char* stack[1024];
    char c, *p1, *p2;
    int n = 0;
    
    if( path == NULL || path[0] != '/' )
        return path;

    p1 = p2 = path;
STR:while(( c = *p1++ ) != '\0' )
    {   switch(c)
        {
        case '/':
NEXT:           stack[n++] = p2;
                *(p2++) = '/';
SKIP:           while( *p1 == '/' )
                    ++p1;
                break;
        case '.':
                // a.b/ or a./
                if( p2 > path && *(p2-1) != '/' )
                {
UNTIL:              while(1)
                    {   *(p2++) = c;
                        switch((c=*p1++))
                        {   case '/' :  goto NEXT;
                            case '\0':  goto END;
                        }
                    }
                }
                switch(*p1)
                {   case '/' :  ++p1; goto SKIP;    // ignore "./"
                    case '\0':  goto STR;           // string end
                    case '.' :                      // pop if "../"
                        if( (*(p1+1)=='/') || (*(p1+1) == '\0') )   
                        {
                            p1++;
                            n--;
                            if( n <= 0 ) // assume the path start with "/"
                            {   p2 = path;
                                n = 0;                                
                                goto NEXT;
                            }
                            p2 = stack[--n];
                            goto NEXT;
                        }
                        //else:  "/..." or "/..a"                    
                    default: ;// "/.a"
                }
        default: // /a/
            goto UNTIL; 
        }
    }
END:
    if( p2 == path )
        *(p2++) = '/';
    else if( *(p2-1) == '/' && p2 > (path+1) )
        --p2;
    *(p2) = '\0';
    return path;
}


      
void test(const char* path)
{
    printf("input: %s; output:", path);
    char* rst = simplifyPath(makeString(path));
    printf("%s\n", rst);
}

int main(void)
{
    test("/home/");
    test("/../");
    test("/home//foo/");
}

// Result 
//
// 2022-11-19: Runtime 3ms 76.92% Memory 6MB 92.31%, https://leetcode.com/problems/simplify-path/submissions/846154370/
// 2023-02-18: Runtime 0ms 100% Memory 6MB 78.57%, https://leetcode.com/problems/simplify-path/submissions/900092384/



