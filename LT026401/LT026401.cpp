#include <lt_help/lt.h>



static int first10Numbers [10] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
static vector<int> uglyNumbers(first10Numbers, first10Numbers + 10);
static int uglyFactors[3] = {2,3,5};

// #define _DBG

class Solution {
public:

    int nthUglyNumber(int n) {

#ifdef _DBG
        cout << "nthUglyNumber n=" << n << endl;
#endif  
        while( n > uglyNumbers.size() )
        {
            int maxUgly = uglyNumbers[ uglyNumbers.size() - 1] + 1;
            int minNextUgly = INT_MAX;
            
            for(int i = 0; i < 3; ++i)
            {              
                int factor = uglyFactors[i];
                int lowUgly = uglyNumbers[ uglyNumbers.size() - 1] / factor + 1;
                auto pos = lower_bound( uglyNumbers.begin(), uglyNumbers.end(), lowUgly);
#ifdef _DBG
                if( pos == uglyNumbers.end())
                    cout << "     lower_bound=" << "not found" << endl; 
                else
                    cout << "     lower_bound=" << *pos << endl; 
#endif 
                int ugly = (*pos) * factor;
                minNextUgly = min( ugly, minNextUgly);
            }
            
            uglyNumbers.push_back(minNextUgly);
        }
        
        return uglyNumbers[ n-1 ];
    }
};


void test(int num)
{
    cout << "input: " << num << "; output: "; 
    int r = Solution().nthUglyNumber(num);
    cout << r << ";" << endl;
}

int main(void)
{
    test(10);
    test(1);
}

// Result 
//
// 2022-11-16: Runtime 5ms 91.43% Memory 6.2MB 91.20%, https://leetcode.com/problems/ugly-number-ii/submissions/844617872/

