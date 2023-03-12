#include <lt_help/lt.h>

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = 0;
        for( int v : arr )
            if( v%2 == 1 )
            {   if( ++n >= 3 )
                    return true;
            }
            else
                n = 0;
        return false;
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    bool r = Solution().threeConsecutiveOdds(arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,34,3,4,5,7,23,12});
}


// Result 
//
// 2022-12-15: Runtime 4ms 64.38% Memory 8.3MB 11.22%, https://leetcode.com/problems/three-consecutive-odds/submissions/859956792/
// 2023-03-11: Runtime 2ms 83.69% Memory 8.2MB 62.55%, https://leetcode.com/problems/three-consecutive-odds/submissions/912968414/



