#include <lt_help/lt.h>

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        std::reverse(num.begin(), num.end());
        int pos = 0, add = 0;
        for( ; k > 0 || add > 0; k /= 10, ++pos, add /= 10)
        {   if( k > 0)
                add += k % 10;
            if (pos >= num.size())
                num.push_back( add % 10 );
            else
            {   add += num[pos];
                num[pos] = add % 10;
            }
        }
        std::reverse(num.begin(), num.end());
        return num;
    }
};



void test(vector<int> num, int k)
{
    cout << "input: k=" << k << ", num=";
    outputVector(num);
    vector<int> r = Solution().addToArrayForm(num, k);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({1,2,0,0}, 34);
}


// Result 
//
// 2022-12-07: Runtime 38ms 35.41% Memory 27.4MB 66.16%, https://leetcode.com/problems/add-to-array-form-of-integer/submissions/855867449/
// 2023-02-18: Runtime 31ms 62.64% Memory 27.2MB 95.69%, https://leetcode.com/problems/add-to-array-form-of-integer/submissions/900118389/



