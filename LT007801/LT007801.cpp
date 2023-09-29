#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int> path;
        _subsets(rst, nums, path, 0);
        return rst;
    }
    
    void _subsets(vector<vector<int>>& rst, vector<int>& nums, vector<int>& path, int index) {
        int size = nums.size();
        if( index == size ){
            rst.push_back(path);
            return;
        }
        
        _subsets(rst, nums, path, index+1);

        path.push_back(nums[index]);
        _subsets(rst, nums, path, index+1);
        path.pop_back();
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<vector<int>> r = Solution().subsets(nums);
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
// 2022-11-19: Runtime 8ms 17.12% Memory 7.1MB 88.14%, https://leetcode.com/problems/subsets/submissions/846151150/
// 2023-02-18: Runtime 2ms 69.43% Memory 7.2MB 71.55%, https://leetcode.com/problems/subsets/submissions/900099242/
// 2023-09-25: Runtime 4ms 47.42% Memory 11 MB 5.2%, https://leetcode.cn/problems/subsets/submissions/469405478/



