#include <lt_help/lt.h>



// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num){return 0;}

class Solution {
public:
    int guessNumber(int n) {
        
        int h = n;
        int l = 1;
        int g = 0;
        int r = 0;
        while( l <= h && (r = guess(g = (l + ( h - l)/2))) != 0 )
        {
            // cout << g << ",l=" << l << ",h=" << h << ",r=" << r << endl;
            if( r == -1)
            {   h = g - 1;
            } else 
            {   l = g + 1; 
            }
        }
        return g;
    }
};
            

int main(void)
{
    cout << "output: done;" << endl;
}

// Result 
//
// 2022-11-21: Runtime 0ms 100% Memory 6MB 55.90%, https://leetcode.com/problems/guess-number-higher-or-lower/submissions/847203109/

