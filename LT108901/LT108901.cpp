#include <lt_help/lt.h>



class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int max_pos = 0, size2 = 0; 
        bool max_dup = true;        
        for(; size2 < size; ++max_pos)
        {   if( arr[max_pos] != 0 )
                ++size2;
            else if ((size2+1) < size)
                size2 += 2;
            else
            {   ++size2;
                max_dup = false;
            }
        }
        // cout << "size=" << size << ", size2=" << size2  << ", max_pos=" << max_pos << ", max_dup=" << max_dup << endl; 
        if( max_pos == size )
            return;
        
        int pos1 = max_pos-1, pos2 = size-1;
        while( pos1 >= 0 && pos1 < pos2)
        {   if( pos1 == (max_pos-1) )
            {   if( arr[pos1] == 0 && max_dup )
                    arr[pos2--] = 0;
                arr[pos2--] = arr[pos1--];
                continue;
            } 
            
            if( arr[pos1] == 0 )
                arr[pos2--] = 0;
            arr[pos2--] = arr[pos1--];
        }
    }
};


void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    Solution().duplicateZeros(arr);
    cout << "; output: ";
    outputVector(arr);
    cout << ";" << endl;
}

int main(void)
{   test({1,0,2,3,0,4,5,0});
}


// Result 
//
// 2022-12-09: Runtime 9ms 61.64% Memory 9.7MB 53.41%, https://leetcode.com/problems/duplicate-zeros/submissions/856930490/



