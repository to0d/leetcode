#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used (nums.size(), false);
        vector<int> entry (nums.size(),0);
        generate(nums,res, used, entry, 0);
        return res;
    }
    
    void generate(vector<int>& nums, vector<vector<int>>& res, vector<bool>& used, vector<int>& entry, int i){
        int len = nums.size();
        if( i == len )
            res.push_back(entry);
        else
            for( int j = 0; j < len; ++j )
                if( !used[j] ) 
                {   used[j] = true;
                    entry[i] = nums[j];
                    generate(nums, res, used, entry, i+1); 
                    used[j] = false;
                }
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums); 
    vector<vector<int>> r = Solution().permute(nums);
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
// 2022-11-16: Runtime 0ms 100% Memory 7.8MB 56.82%, https://leetcode.com/problems/permutations/submissions/844587264/
// 2023-02-17: Runtime 3ms 75.31% Memory 7.7MB 79.87%, https://leetcode.com/problems/permutations/submissions/899807597/
// 2023-03-14: Runtime 3ms 73.48% Memory 7.8MB 55.11%, https://leetcode.com/problems/permutations/submissions/914478388/


