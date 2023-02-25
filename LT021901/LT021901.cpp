#include <lt_help/lt.h>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if( k <= 0 ) 
            return false;
        
        unordered_map<int,int> dup_map;
        for( int i = 0; i < nums.size(); ++i )
        {   int n = nums[i];
            auto iter = dup_map.find(n);
            if( iter != dup_map.end() && ((i - iter->second)<=k) )
                return true;
            dup_map[n] = i;
        }
        
        return false;
    }
};


void test(vector<int> nums, int k)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    bool r = Solution().containsNearbyDuplicate(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,2,3,1}, 3);
}

// Result 
//
// 2022-11-19: Runtime 243ms 36.80% Memory 77.4MB 45.61%, https://leetcode.com/problems/contains-duplicate-ii/submissions/846321439/
// 2023-02-17: Runtime 190ms 65.19% Memory 77.4MB 30.55%, https://leetcode.com/problems/contains-duplicate-ii/submissions/899779619/
