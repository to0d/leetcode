#include <lt_help/lt.h>



class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> rst;
        int v = 0;
        for(int n : nums)
        {   v = (v << 1) | n;
            if(v%5==0)
            {   rst.push_back(true);
                v = 0;
            }
            else 
            {   rst.push_back(false);
                if( v > 5 )
                    v -= 5;
            }
        }
        return rst;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<bool> r = Solution().prefixesDivBy5(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({0,1,1});
}


// Result 
//
// 2022-12-08: Runtime 7ms 97.3% Memory 14MB 52.42%, https://leetcode.com/problems/binary-prefix-divisible-by-5/submissions/856390914/



