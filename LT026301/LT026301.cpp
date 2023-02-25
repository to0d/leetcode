#include <lt_help/lt.h>



class Solution {
public:

    bool isUgly(int num) {
     
        if( num == 0 ) return false;
        if( num == 1 ) return true;
        if( num % 2 == 0 ) return isUgly( num / 2);
        if( num % 3 == 0 ) return isUgly( num / 3);
        if( num % 5 == 0 ) return isUgly( num / 5);
        
        return false;
    }
};


void test(int num)
{
    cout << "input: " << num << "; output: "; 
    bool r = Solution().isUgly(num);
    cout << r << ";" << endl;
}

int main(void)
{
    test(6);
    test(1);
    test(14);
}

// Result 
//
// 2022-11-16: Runtime 0ms 100% Memory 5.8MB 80.2%, https://leetcode.com/problems/ugly-number/submissions/844615910/

