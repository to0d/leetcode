#include <lt_help/lt.h>



// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {return true;};

class Solution {
public:
    int firstBadVersion(int n) 
    {        
        int h = n;
        int l = 1;
        while( l <= h )
        {
            // int m = (h+l)/2;
            int m = (h-l)/2+l;
            if( isBadVersion(m) )
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};

int main(void)
{
    cout << "output: done; " << endl;
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 5.7MB 100%, https://leetcode.com/problems/first-bad-version/submissions/846335929/

