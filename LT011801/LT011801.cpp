#include <lt_help/lt.h>



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        vector<int> row;
        for(int i = 0; i < numRows; i++){
            row.push_back(1);
            for(int j = i - 1; j > 0; j--){
                row[j] = row[j - 1] + row[j];
            }
            result.push_back(row);
        }

        return result;
    }
};          


void test(int n)
{
    cout << "input: " << n;
    vector<vector<int>> r = Solution().generate(n);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(5); 
}


// Result 
//
// 2022-11-24: Runtime 0ms 100% Memory 6.5MB 91.69%, https://leetcode.com/problems/pascals-triangle/submissions/849021522/

