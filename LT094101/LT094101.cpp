#include <lt_help/lt.h>

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size(), peak = 0;
        while( (peak+1) < size && arr[peak+1] > arr[peak])
            ++peak;
        
        if( peak == 0 || peak == (size-1))
            return false;
        
        while( (peak+1) < size && arr[peak+1] < arr[peak])
            ++peak;
        
        return peak == (size-1);
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    bool r = Solution().validMountainArray(arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({0,3,2,1});
}


// Result 
//
// 2022-12-06: Runtime 38ms 29.35% Memory 22.5MB 9.14%, https://leetcode.com/problems/valid-mountain-array/submissions/855603799/
// 2023-02-24: Runtime 20ms 98.23% Memory 22.5MB 9.48%, https://leetcode.com/problems/valid-mountain-array/submissions/904199112/



