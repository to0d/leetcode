#include <lt_help/lt.h>



class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int pos1 = 0, pos2 = 1, size = arr.size();
        //for(int v : arr ) cout << " " << v; cout << endl;
        while( pos1 < size && pos2 < size )
        {   int v1 = arr[pos1];
            int v2 = arr[pos2];
            if( v1 < 0 )
            {   if( v2 > 0 )
                    ++pos1;
                else
                {   int vv = 2*v2;
                    if( v1 == vv )
                        return true;
                    if( v1 > vv )
                        ++pos2;
                    else
                        ++pos1;
                }
            }
            else
            {
                int vv = 2*v1;
                
                if( v2 == vv )
                    return true;
                if( v2 > vv )
                    ++pos1;
                else
                    ++pos2;
            }
            if( pos1 >= pos2 )
                pos2 = pos1 + 1;
        }
        return false;
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    bool r = Solution().checkIfExist(arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({10,2,5,3});
}


// Result 
//
// 2022-12-13: Runtime 7ms 76.22% Memory 10.1MB 42.38%, https://leetcode.com/problems/check-if-n-and-its-double-exist/submissions/858707616/



