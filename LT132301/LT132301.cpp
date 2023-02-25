#include <lt_help/lt.h>

class Solution {
public:
    int maximum69Number (int num) {
        int n = num, a = 0;
        for(int x=1; n > 0; n/=10, x*= 10)
            if( n%10 == 6 )
                a = 3*x;
        return num + a;
    }
};



void test(int num)
{
    cout << "input: " << num;
    int r = Solution().maximum69Number(num);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(9669);
}


// Result 
//
// 2022-12-12: Runtime 3ms 39.3% Memory 5.9MB 67.81%, https://leetcode.com/problems/maximum-69-number/submissions/858493826/
// 2023-02-24: Runtime 0ms 100% Memory 5.9MB 95.21%, https://leetcode.com/problems/maximum-69-number/submissions/904207185/



