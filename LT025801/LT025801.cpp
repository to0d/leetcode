#include <lt_help/lt.h>



class Solution {
public:
    int addDigits(int num) {
        return (num-1) %9 + 1;   
    }
};


void test(int num)
{
    cout << "input: " << num;
    int r = Solution().addDigits(num);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test(0);
    test(38);
}

// Result 
//
// 2022-11-19: Runtime 3ms 57.43% Memory 6MB 10.4%, https://leetcode.com/problems/add-digits/submissions/846332848/
