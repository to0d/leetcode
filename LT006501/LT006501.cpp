#include <lt_help/lt.h>

class Solution {
public:
#define CT_CHARE        0           // character e
#define CT_NUM          1           // number
#define CT_PERIOD       2           // Symbol .
#define CT_MINUS        3           // Symbol -
#define CT_OTHER        4           // Other Symbol

    bool isNumber(string s){
        int size = s.size(), cur_state = 0, last_state  = 0, num1 = 0, num2 = 0, pos = 0;
        
        while(pos < size && s.at(pos) == ' ')
            ++pos;

        while(pos < size && s.at(size - 1) == ' ')
            --size;
        
        if( pos >= size)
            return false;
        
        // +3.5e+3
        // 1234567
        static int DFA_SCAN_STATE[8][5] = {
            //-E -N- "."  -+ 
            { -1, 2,  3,  1 }, // 0
            { -1, 2,  3, -1 }, // 1  +-    
            {  5, 2,  3, -1 }, // 2  3
            {  5, 4, -1, -1 }, // 3  .
            {  5, 4, -1, -1 }, // 4  5
            { -1, 7, -1,  6 }, // 5  e
            { -1, 7, -1, -1 }, // 6  +-
            { -1, 7, -1, -1 }, // 7  3
        };
        
        for(; pos < size; ++pos, last_state = cur_state)
        {   int char_type = charTypeOf(s.at(pos));
            if (char_type == CT_OTHER)
                return false;
            
            cur_state = DFA_SCAN_STATE[last_state][char_type];
            if( cur_state == -1 )
                return false;
            
            if( char_type == CT_NUM)
            {   if( cur_state < 5 )
                    ++num1;
                else
                    ++num2;
            } 
        }
        
        if( num1 == 0 || (last_state > 5 && num2 == 0))
            return false;

        return last_state  == 2 || last_state == 3 || last_state == 4 || last_state == 7 || last_state == 9 || last_state == 10;
    }
    
    int charTypeOf(char c){
        if( isdigit(c) )
            return CT_NUM;
        switch( c)
        {   case 'e':
            case 'E': return CT_CHARE;
            case '.': return CT_PERIOD;
            case '-':
            case '+': return CT_MINUS;
            default:
                return CT_OTHER;
        }
    }
};



void test(string s)
{
    cout << "input: " << s << "; output: ";
    bool r = Solution().isNumber(s);
    cout << r << ";" << endl;
}

int main(void)
{
    test("0");
}

// Result 
//
// 2022-11-18: Runtime 7ms 26.88% Memory 6MB 47.37%, https://leetcode.com/problems/valid-number/submissions/845892136/
// 2023-02-18: Runtime 0ms 100% Memory 6.1MB 47.29%, https://leetcode.com/problems/valid-number/submissions/900081688/


