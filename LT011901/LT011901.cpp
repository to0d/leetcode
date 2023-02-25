#include <lt_help/lt.h>




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for(int i = 0; i <= rowIndex; i++){
            row.push_back(1);
            for(int j = i - 1; j > 0; j--){
                row[j] = row[j - 1] + row[j];
            }
        }
		return row;
    }
};         


void test(int rowIndex)
{
    cout << "input: " << rowIndex;
    vector<int> r = Solution().getRow(rowIndex);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(3); 
}


// Result 
//
// 2022-12-30: Runtime 4ms 34.41% Memory 6.5MB 50.35%, https://leetcode.com/problems/pascals-triangle-ii/submissions/867831725/
