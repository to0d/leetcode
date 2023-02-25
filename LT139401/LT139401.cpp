#include <lt_help/lt.h>

class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int size = arr.size(), lastVal = arr[size - 1] + 1, lastCount = 0;
        for(int pos = size -1; pos >= 0; --pos )
        {   int v = arr[pos];
            if( v != lastVal )
            {   if( lastCount > 0 && lastCount == lastVal )
                    return lastVal;        
                lastVal   = v;
                lastCount = 1;
            }
            else
                ++lastCount;
        }

        return lastCount > 0 && lastCount == lastVal ? lastVal : -1;
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    int r = Solution().findLucky(arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({2,2,3,4});
}


// Result 
//
// 2022-12-14: Runtime 12ms 27.3% Memory 10.2MB 95.36%, https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/859450139/
// 2023-02-25: Runtime 8ms 57.13% Memory 10.1MB 95.30%, https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/904214057/



