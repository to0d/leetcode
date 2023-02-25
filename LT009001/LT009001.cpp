#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        uniqNums.clear();
        uniqCounts.clear();

        unordered_map<int,int> dmap;
        for( int n : nums)
            dmap[n]++;

        for( auto& pm : dmap)
        {   uniqNums.push_back(pm.first);
            uniqCounts.push_back(pm.second);
        }
        
        number_count = uniqNums.size();
        int buffer[256];

        findSubSets(buffer, 0,0);
        return res;
    }
    
    void findSubSets(int* buffer, int bufLen, int pos){
        res.push_back( vector<int>(buffer, buffer+bufLen));
        for(int i = pos; i < number_count; ++i)
        {   int c = uniqCounts[i];
            int n = uniqNums[i];
            for( int j = 1; j <= c; ++j )
            {   int len = bufLen;
                for( int k = 0; k < j; ++k)
                    buffer[len++] = n;
                findSubSets(buffer, len, i + 1);
            }
        }
    }
    
    int number_count;
    vector<vector<int>> res;
    vector<int> uniqNums;
    vector<int> uniqCounts; 
};
            


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    vector<vector<int>> r = Solution().subsetsWithDup(nums);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({1,2,2});
}

// Result 
//
// 2022-11-23: Runtime 0ms 100% Memory 7.8MB 51.52%, https://leetcode.com/problems/subsets-ii/submissions/848363623/
// 2023-02-18: Runtime 0ms 100% Memory 7.5MB 87.41%, https://leetcode.com/problems/subsets-ii/submissions/900103307/

