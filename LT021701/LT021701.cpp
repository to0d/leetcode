#include <lt_help/lt.h>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dup_set;
        for( int n : nums )
        {   if( dup_set.count(n) != 0) 
                return true;
            dup_set.insert(n);
        }
        return false;
    }
};


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    bool r = Solution().containsDuplicate(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,2,3,1});
}

// Result 
//
// 2022-11-19: Runtime 101ms 85.89% Memory 51.4MB 74.24%, https://leetcode.com/problems/contains-duplicate/submissions/846320277/
// 2023-02-17: Runtime 141ms 50.18% Memory 69.5MB 33.1%, https://leetcode.com/problems/contains-duplicate/submissions/899780671/
