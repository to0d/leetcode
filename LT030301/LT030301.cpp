#include <lt_help/lt.h>

class NumArray {
public:
    NumArray(vector<int>& nums){
        int sum = 0;
        for(auto num : nums)
        {   sum += num;
            sumArray.push_back(sum);
        }
    }

    int sumRange(int i, int j){   
        return getSum(j) - getSum(i-1); 
    }
    
    int getSum(int i){  
        return i < 0 ? 0 : sumArray[i]; 
    }
    
    vector<int> sumArray;
};

 
vector<int> nums1 = {-2, 0, 3, -5, 2, -1};
NumArray numArray(nums1);

void test(int i, int j)
{
    cout << "input: i=" << i << ", j=" << j;
    int r = numArray.sumRange(i, j); 
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(0, 2);
    test(2, 5);
    test(0, 5);
}

// Result 
//
// 2022-11-22: Runtime 46ms 39.87% Memory 17.1MB 77.24%, https://leetcode.com/problems/range-sum-query-immutable/submissions/847764646/
// 2023-02-22: Runtime 30ms 51.26% Memory 17.1MB 38.4%, https://leetcode.com/problems/range-sum-query-immutable/submissions/902738048/


