#include <lt_help/lt.h>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size = arr.size();
        if( size <= 1 )
            return true;
        
        vector<int> countArr;
        std::sort(arr.begin(), arr.end());
        
        int last = arr[0], count = 1;
        for(int i = 1; i < size; ++i)
        {   if( arr[i] == last )
                ++count;
            else
            {   countArr.push_back(count);
                last  = arr[i];
                count = 1;
            }
        }

        countArr.push_back(count);
        std::sort(countArr.begin(), countArr.end());
        
        last = -1;
        for(int c : countArr)
            if( c == last )
                return false;
            else
                last = c;
        
        return true;
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    bool r = Solution().uniqueOccurrences(arr);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({1,2,2,1,1,3});
}


// Result 
//
// 2022-12-12: Runtime 6ms 37.54% Memory 8.2MB 78.37%, https://leetcode.com/problems/unique-number-of-occurrences/submissions/858404195/
// 2023-02-24: Runtime 3ms 77.34% Memory 8.2MB 57.79%, https://leetcode.com/problems/unique-number-of-occurrences/submissions/904204567/



