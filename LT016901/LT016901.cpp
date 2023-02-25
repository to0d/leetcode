#include <lt_help/lt.h>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> nmap;
        for( int n : nums )
        {   if( (++nmap[n]) > nums.size()/2 )
                    return n;
        }

        return 0;
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
