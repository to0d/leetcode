#include <lt_help/lt.h>



bool less_interval(const vector<int>& a, const vector<int>& b)
{   return a[0] < b[0];
}

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int size = nums.size();
        for(int i = 0;i < size; ++i)
        {   int idx = index[i];
            if( idx != i ) 
            {   for(int j = 0;j < i; ++j)
                    if( index[j] >= idx )
                        index[j]++;
            }
        }
        //for( int idx : index ) cout << " " << idx; cout << endl;
        vector<vector<int>> pairs;
        for(int i = 0;i < size; ++i)
        {   vector<int> r = {index[i], nums[i]};
            pairs.push_back(r);
        }
        std::sort(pairs.begin(), pairs.end(), less_interval);
        //for( vector<int>& p : pairs ) cout << " [" << p[0] << "," << p[1] <<"]"; cout << endl;
        vector<int> rst;
        for( vector<int>& p : pairs )
            rst.push_back(p[1]);
        return rst;
    }
};



void test(vector<int> nums, vector<int> index)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", index=";
    outputVector(index);
    vector<int> r = Solution().createTargetArray(nums, index);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({0,1,2,3,4}, {0,1,2,2,1});
}


// Result 
//
// 2022-12-13: Runtime 0ms 100% Memory 8.6MB 13.46%, https://leetcode.com/problems/create-target-array-in-the-given-order/submissions/859209254/



