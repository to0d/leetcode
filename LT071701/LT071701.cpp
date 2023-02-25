#include <lt_help/lt.h>

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size(); 
        if( len <= 1 )
            return true;
        
        if( bits[len-2] == 0 && bits[len-1] )
            return false;
        
        int i = 0;
        bool isOne = true;
        while( i < len )
        {   if( bits[i] == 0 )
            {   i+=1;
                isOne = true;
            }
            else
            {   i+=2;
                isOne = false;
            }
        }

        return isOne;
    }
};
    


void test(vector<int> bits)
{
    cout << "input: ";
    outputVector(bits); 
    bool r = Solution().isOneBitCharacter(bits);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test({1,0,0});
}

// Result 
//
// 2022-11-19: Runtime 8ms 23.19% Memory 9.7MB 64.56%, https://leetcode.com/problems/1-bit-and-2-bit-characters/submissions/846375175/
// 2023-02-24: Runtime 6ms 34.81% Memory 9.7MB 17.41%, https://leetcode.com/problems/1-bit-and-2-bit-characters/submissions/904190088/


