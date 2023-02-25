#include <lt_help/lt.h>

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size(), column = strs[0].length();
        if( row <= 1 )
            return 0;
        int del = 0;
        for(int i = 0; i < column; ++i)
        {   bool find = false;
            for(int j = 1; !find && j < row; ++j)
                if( strs[j].at(i) < strs[j-1].at(i))
                    find = true;
            if( find )
               ++del; 
        }
        return del;
    }
};



void test(vector<string> strs)
{
    cout << "input: ";
    outputVector(strs);
    int r = Solution().minDeletionSize(strs);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({"cba","daf","ghi"});
}


// Result 
//
// 2022-12-06: Runtime 96ms 48.43% Memory 12.1MB 67.44%, https://leetcode.com/problems/delete-columns-to-make-sorted/submissions/855610614/
// 2023-02-18: Runtime 39ms 98.44% Memory 12.2MB 24.72%, https://leetcode.com/problems/delete-columns-to-make-sorted/submissions/900118827/



