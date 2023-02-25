#include <lt_help/lt.h>

uint32_t reverseBits(uint32_t n) {
    
    uint32_t ML = 0x1;
    uint32_t MH = 0x80000000;
    int i;
    
    for( i=0; i<16; ++i, ML<<=1, MH>>=1)
    {
        uint32_t lb = n & ML;
        uint32_t lh = n & MH;
        
        if( lb == ML)
            n |= MH;
        else
            n &= ~MH;
        if( lh == MH)
            n |= ML;
        else
            n &= ~ML;
    }
    
    return n;
}


void test(uint32_t n)
{
    printf("input: %d", n);  
    uint32_t r = reverseBits(n);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test(43261596);
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 5.5MB 15.21%, https://leetcode.com/problems/reverse-bits/submissions/846359366/

