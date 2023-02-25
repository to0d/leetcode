#include <lt_help/lt.h>  

int romanToInt(char* s) {
    int len;
    if( s == NULL || (len=strlen(s)) == 0 )
        return 0;
    
    static int RomainMap[256] = {0};
    static int RMInit = 0;
    if( RMInit == 0)
    {
        RomainMap['I'] = 1;
        RomainMap['V'] = 5;
        RomainMap['X'] = 10;
        RomainMap['L'] = 50;
        RomainMap['C'] = 100;
        RomainMap['D'] = 500;
        RomainMap['M'] = 1000;
        RMInit = 1;
    }

    int num = 0, pos = 0;
    while( pos < len )
    {
        char c = s[pos];
        
        int pos2 = pos + 1;
        while( pos2 < len && s[pos2] == c )
            pos2++;
        
        if( pos2 == len )
        {   num += RomainMap[c]*(pos2-pos);
            break;
        }
        else
        {   char c2 = s[pos2];
            if( RomainMap[c2] < RomainMap[c] )
            {   num += RomainMap[c]*(pos2-pos);
                pos = pos2;
            }
            else
            {   num += RomainMap[c2] - RomainMap[c]*(pos2-pos);
                pos = pos2+1;
            }
        }
    }
    
    return num;    
}

void test(const char* s)
{
    printf("input: %s", s);
    int r = romanToInt(makeString(s));
    printf("; output: %d\n", r);
}

int main(void)
{
    test("MCMXCIV");
}

// Result 
//
// 2022-11-02: Runtime 13ms 26.39% Memory 5.8MB 87.81%, https://leetcode.com/problems/roman-to-integer/submissions/835439060/
// 2023-02-15: Runtime 8ms 66.11% Memory 6.1MB 10.86%, https://leetcode.com/problems/roman-to-integer/submissions/898530082/

