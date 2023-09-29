#include <lt_help/lt.h>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long prduct = 1, zero_idx = -1, idx = 0;
        
        for(int num : nums){
            if( num == 0 ){
                if( zero_idx != -1 )
                    return vector<int>(nums.size(), 0);
                else
                    zero_idx = idx;
            }
            else
                prduct *= num;
            idx++;
        }
        
        if( zero_idx != -1 ){
            vector<int> rst(nums.size(), 0);
            rst[zero_idx] = (int) prduct;
            return rst;
        }
        
        vector<int> rst;
        for(int num : nums)
            rst.push_back( (int) prduct/num ); 
        
        return rst;
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
// 2023-09-27: Runtime 24ms 52.65% Memory 25MB 12.37%, https://leetcode.cn/problems/product-of-array-except-self/submissions/469959247/



