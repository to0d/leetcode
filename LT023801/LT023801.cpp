#include <lt_help/lt.h>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long all = 1, zero = 0;
        for(int num : nums)
        {   if( num == 0 )
            {   if(zero++ > 1)
                    break;
            }
            else
                all *= num;
        }

        if( zero > 1 )
            return vector<int>(nums.size(), 0);

        vector<int> vec;
        for(int num : nums)
        {   int val;
            if( zero == 0 )
                val = (int)(all/num);
            else if( num == 0 )
                val = (int) all;
            else 
                val = 0;
            vec.push_back( val );
        }

        return vec;
    }
};



void test(vector<int> nums)
{
    cout << "input: "; 
    outputVector(nums); 
    vector<int> r = Solution().productExceptSelf(nums);
    cout << "; output: ";
    outputVector(r); 
    cout << ";" << endl;
}


int main(void)
{
    test({1,2,3,4});
}

// Result 
//
// 2023-02-05: Runtime 28ms 62.76% Memory 24.8MB 48.7%, https://leetcode.com/problems/product-of-array-except-self/submissions/892013758/
// 2023-03-12: Runtime 20ms 91.53% Memory 25MB 33.24%, https://leetcode.com/problems/product-of-array-except-self/submissions/913752287/



