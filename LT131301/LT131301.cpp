#include <lt_help/lt.h>



class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int size = nums.size();
        vector<int> rst;
        for(int i = 0;i < size; i += 2)
        {   int freq = nums[i];
            int val  = nums[i+1];
            for(int j = 0; j < freq; ++j)
                rst.push_back(val);
        }
        return rst;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<int> r = Solution().decompressRLElist(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({1,2,3,4});
}


// Result 
//
// 2022-12-21: Runtime 2ms 92.93% Memory 10.1MB 12.65%, https://leetcode.com/problems/decompress-run-length-encoded-list/submissions/862983241/



