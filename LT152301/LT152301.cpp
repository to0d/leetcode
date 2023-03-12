#include <lt_help/lt.h>

class Solution {
public:
#define isOdd(x) ((x)%2 == 1)
    int countOdds(int low, int high) {
        int count = 0;
        if( isOdd(high) )
        {   ++count;
            --high;
        }
        if( isOdd(low) )
        {   ++count;
            ++low;
        }
        return (high-low)/2 + count;
    }
};



void test(int low, int high)
{
    cout << "input: low=" << low << ", high=" << high;
    int r = Solution().countOdds(low, high);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test(3, 7);
}


// Result 
//
// 2022-12-20: Runtime 3ms 66.26% Memory 6MB 7.77%, https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/862419208/
// 2023-03-11: Runtime 0ms 100% Memory 6MB 10.35%, https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/912972538/



