#include <lt_help/lt.h>


// f(n) =  max( 1-f(n-1), 1-f(n-2), 1-f(n-3))     ; when n > 3
//         1                                      ; when 1<= n <= 3
// 
// n :=  1 2 3 4 5 6 7 8 9 10..   4m 4m+1 4m+2 4m+3  4m+4 
// r  =  1 1 1 0 1 1 1 0 1         0  1    1    1     0 
class Solution {
public:
    bool canWinNim(int n) {
         return n % 4 != 0;   
    }
};



void test(int n)
{
    cout << "input: " << n;
    bool r = Solution().canWinNim(n);
    cout << "; output: " << r << endl;
}


int main(void)
{
    test(4);
}

// Result 
//
// 2022-11-19: Runtime 4ms 41.50% Memory 5.9MB 79.8%, https://leetcode.com/problems/nim-game/submissions/846342808/
// 2023-02-22: Runtime 0ms 100% Memory 6MB 51.53%, https://leetcode.com/problems/nim-game/submissions/902735347/

