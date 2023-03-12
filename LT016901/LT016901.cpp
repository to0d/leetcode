#include <lt_help/lt.h>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], count=0;
        for(int num : nums){
            if( count == 0 )
                maj = num;
            count += maj == num ? 1 : -1;
        }
        return maj;
    }
};
  

   
void test(vector<int>& nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().majorityElement(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    vector<int> nums = {3,2,3};
    test(nums);
}

// Result 
//
// 2022-11-21: Runtime 35ms 14.48% Memory 19.6MB 75.49%, https://leetcode.com/problems/majority-element/submissions/847492749/
// 2023-02-20: Runtime 24ms 48.40% Memory 19.6MB 33.87%, https://leetcode.com/problems/majority-element/submissions/901598041/
// 2023-03-12: Runtime 21ms 61.95% Memory 19.6MB 80.69%, https://leetcode.com/problems/majority-element/submissions/913862794/, https://leetcode.com/problems/majority-element/solutions/3109595/100-faster-c-with-explanation-o-1-space/
