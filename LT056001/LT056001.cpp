#include <lt_help/lt.h>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, ans=0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto it:nums){
            sum += it;
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};



void test(vector<int> nums, int k)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    int r = Solution().subarraySum(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,3}, 3);
}


// Result 
//
// 2023-03-11: Runtime 87ms 87.97% Memory 41.6MB 60.83%, https://leetcode.com/problems/subarray-sum-equals-k/submissions/913167424/, https://leetcode.com/problems/subarray-sum-equals-k/solutions/1760146/c-easy-solution-prefix-sum-map-easy-understanding-hashmap/
// 2023-03-17: Runtime 92ms 75.52% Memory 47MB 21.97%, https://leetcode.com/problems/subarray-sum-equals-k/submissions/916681236/


