#include <lt_help/lt.h>

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int size = arr.size();
        for(int i = 0;i < size; ++i)
        {   for(int j = 1; j < (size-i); ++j)
            {   if( arr[j] < arr[j-1])
                {   int v = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = v;
                }
                if( target[j] < target[j-1])
                {   int v = target[j-1];
                    target[j-1] = target[j];
                    target[j] = v;
                }
            }

            if( arr[size-i-1] != target[size-i-1])
                return false;
        }

        return true;
    }
};



void test(vector<int> target, vector<int> arr)
{
    cout << "input: target=";
    outputVector(target);
    cout << ", arr=";
    outputVector(arr);
    bool r = Solution().canBeEqual(target, arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,3,4}, {2,4,1,3});
}


// Result 
//
// 2022-12-15: Runtime 103ms 5.2% Memory 14.5MB 63.47%, https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/submissions/860215688/
// 2023-02-25: Runtime 95ms 5.6% Memory 14.5MB 31.86%, https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/submissions/904215408/



