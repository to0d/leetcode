#include <lt_help/lt.h>



class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        
        unsigned char byte1 = reverseByte((unsigned char)( n >> 28)& 0x0000000F );
        unsigned char byte2 = reverseByte((unsigned char)( n >> 24)& 0x0000000F );
        unsigned char byte3 = reverseByte((unsigned char)( n >> 20)& 0x0000000F );
        unsigned char byte4 = reverseByte((unsigned char)( n >> 16)& 0x0000000F );
        unsigned char byte5 = reverseByte((unsigned char)( n >> 12)& 0x0000000F );
        unsigned char byte6 = reverseByte((unsigned char)( n >> 8) & 0x0000000F );
        unsigned char byte7 = reverseByte((unsigned char)( n >> 4) & 0x0000000F ) ;
        unsigned char byte8 = reverseByte((unsigned char)( n >> 0) & 0x0000000F );
     
        return ( byte8 << 28) | 
               ( byte7 << 24) | 
               ( byte6 << 20) | 
               ( byte5 << 16) | 
               ( byte4 << 12) |
               ( byte3 << 8)  |
               ( byte2 << 4)  |
               byte1; 
    }
    
    inline unsigned char reverseByte(unsigned char byte) { return reverseMap[byte]; }
    static unsigned char reverseMap[16];
};

unsigned char Solution::reverseMap[16] = {
        0,   // 0000 ==> 0000
        8,   // 0001 ==> 1000
        4,   // 0010 ==> 0100
       12,   // 0011 ==> 1100
        2,   // 0100 ==> 0010
       10,   // 0101 ==> 1010
        6,   // 0110 ==> 0110
       14,   // 0111 ==> 1110
        1,   // 1000 ==> 0001
        9,   // 1001 ==> 1001
        5,   // 1010 ==> 0101
       13,   // 1011 ==> 1101
        3,   // 1100 ==> 0011
       11,   // 1101 ==> 1011
        7,   // 1110 ==> 0111
       15,   // 1111 ==> 1111        
};
    


void test(uint32_t n)
{
    cout << "input: " << n;
    uint32_t r = Solution().reverseBits(n);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(43261596);
}

// Result 
//
// 2022-11-19: Runtime 3ms 60.80% Memory 6.1MB 36.73%, https://leetcode.com/problems/reverse-bits/submissions/846357313/

