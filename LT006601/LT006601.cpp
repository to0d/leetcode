#include <lt_help/lt.h>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> rst;       
        int add = 1, val = 0;
        for( auto it = digits.rbegin(); it != digits.rend(); ++it)
        {   val = add + *it;
            add = 0;
            if( val >= 10 )
            {   add = 1;
                val -= 10;
            }
            rst.push_back(val);
        }

        if(add != 0)
            rst.push_back(add);

        std::reverse(rst.begin(), rst.end());
        return rst;
    }
};



void test(vector<int> digits)
{
    cout << "input: ";
    outputVector(digits);
    vector<int> r = Solution().plusOne(digits);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({1,2,3});
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 8.8MB 18.91%, https://leetcode.com/problems/plus-one/submissions/845895343/
// 2023-02-18: Runtime 0ms 100% Memory 8.6MB 88.92%, https://leetcode.com/problems/plus-one/submissions/900083652/

