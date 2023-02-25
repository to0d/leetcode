#include <lt_help/lt.h>

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 0, h = num, t = num;
        while( l <= h )
        {   long m  = (l+h)/2;
            long m2 = m*m;
            if( m2 == num )
                return true;            
            else if( m2 < num )
                l = m + 1;
            else
                h = m - 1;
        }
        return false;
    }
};



void test(int num)
{
    cout << "input: " << num;
    bool r = Solution().isPerfectSquare(num);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(16);
}

// Result 
//
// 2023-01-09: Runtime 3ms 47.10% Memory 5.9MB 51.16%, https://leetcode.com/problems/valid-perfect-square/submissions/874777921/
// 2023-02-22: Runtime 0ms 100% Memory 6MB 51.29%, https://leetcode.com/problems/valid-perfect-square/submissions/902941938/



