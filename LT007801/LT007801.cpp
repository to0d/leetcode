#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>r;
        findSubSets(res,nums,r,0);
        return res;
    }

    void findSubSets(vector<vector<int>>& res, vector<int>& nums, vector<int>& r, int pos){
        res.push_back(r);
        for(int i = pos; i < nums.size(); ++i)
        {   r.push_back( nums[i] );
            findSubSets(res, nums, r, i + 1);
            r.pop_back();
        }
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


