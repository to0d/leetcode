#include <lt_help/lt.h>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0, ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
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


