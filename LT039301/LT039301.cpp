#include <lt_help/lt.h>



#define MASK_BIT_8 0x80
#define MASK_BIT_87 0xC0
#define MASK_BIT_876 0xE0
#define MASK_BIT_8765 0xF0
#define MASK_BIT_87654 0xF8

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, size = data.size();
        while(i < size)
        {   int v0 = data[i];
            if( v0 > 0xFF ) 
                return false;
            if( (v0 & MASK_BIT_8) == 0 ) // 0xxxxxxx
                i++;
            else if( ((i+1)<size) // 110xxxxx 10xxxxxx
             && ((v0&MASK_BIT_876) == MASK_BIT_87)
             && ((data[i+1]&MASK_BIT_87) == MASK_BIT_8) )
                i += 2;
            else if( ((i+2)<size) // 1110xxxx 10xxxxxx 10xxxxxx
             && ((v0&MASK_BIT_8765) == MASK_BIT_876)
             && ((data[i+1]&MASK_BIT_87) == MASK_BIT_8)
             && ((data[i+2]&MASK_BIT_87) == MASK_BIT_8) )
                i += 3;
            else if( ((i+3)<size) // 1110xxxx 10xxxxxx 10xxxxxx
             && ((v0&MASK_BIT_87654) == MASK_BIT_8765)
             && ((data[i+1]&MASK_BIT_87) == MASK_BIT_8)
             && ((data[i+2]&MASK_BIT_87) == MASK_BIT_8)
             && ((data[i+3]&MASK_BIT_87) == MASK_BIT_8) )
                i += 4;
            else
                return false;
        }
        return true;
    }
};


void test(vector<int> data)
{
    cout << "input: "; 
    outputVector(data); 
    bool r = Solution().validUtf8(data);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({197,130,1});
}

// Result 
//
// 2023-01-28: Runtime 15ms 54.89% Memory 14.1MB 63.53%, https://leetcode.com/problems/utf-8-validation/submissions/886880083/



