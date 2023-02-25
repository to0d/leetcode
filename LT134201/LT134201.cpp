#include <lt_help/lt.h>



class Solution {
public:
    int numberOfSteps(int num) {
        int n = 0;
        while( num > 0 )
        {   if( num %2 == 1)
                --num;
            else
                num /= 2;
            ++n;
        }
        return n;
    }
};


void test(int num)
{
    cout << "input: " << num;
    int r = Solution().numberOfSteps(num);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(14);
}


// Result 
//
// 2022-12-12: Runtime 0ms 100% Memory 6MB 8.27%, https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/submissions/858661510/



