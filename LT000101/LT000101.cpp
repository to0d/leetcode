#include <lt_help/lt.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> idxMap;
        int idx = 0;
        for( auto num : nums )
        {   auto it = idxMap.find(target - num);
            if( it != idxMap.end() )
                return {it->second, idx};
            idxMap[num] = idx++;
        }
        return {};
    }
};


void test(vector<int> input, int target)
{    
    cout << "input: nums=";  
    outputVector(input); 
    cout << ", target=" << target;
    vector<int> r = Solution().twoSum(input, target);
    cout << "; output: ";
    outputVector(r); 
    cout << ";" << endl;
}

int main(void)
{
    test({2, 7, 11, 15}, 9);
}

// Result 
//
// 2023-02-06: Runtime 11ms 87.54% Memory 11.1MB 19.19%, https://leetcode.com/problems/two-sum/submissions/892660439/
// 2023-07-20: Runtime 8 ms 91.52% Memory 10.7 MB 18.78%, https://leetcode.cn/submissions/detail/448556175/



