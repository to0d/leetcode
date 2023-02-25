#include <lt_help/lt.h>

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        for( int v : bills )
            switch(v)
            {   case 5 : 
                    ++ c5; 
                    break;
                case 10:
                    if( c5-- == 0)
                        return false;
                    ++ c10;
                    break;
                case 20:
                    if( c5 > 0 && c10 > 0 )
                    {   --c5;
                        --c10;
                        ++c20;
                    }
                    else if ( c5 >= 3 )
                    {   c5 -= 3;
                        ++c20;
                    }
                    else
                       return false;
                    break;
            }
        return true;
    }
};



void test(vector<int> bills)
{
    cout << "input: ";
    outputVector(bills);
    bool r = Solution().lemonadeChange(bills);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({5,5,5,10,20});
}


// Result 
//
// 2022-12-04: Runtime 296ms 5.18% Memory 83.5MB 56.25%, https://leetcode.com/problems/lemonade-change/submissions/854340660/
// 2023-02-24: Runtime 110ms 80.93% Memory 83.5MB 10.7%, https://leetcode.com/problems/lemonade-change/submissions/904196378/



