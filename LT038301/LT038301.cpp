#include <lt_help/lt.h>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[256] = {0}, b[256] = {0}; 

        calculate(ransomNote, a);
        calculate(magazine, b);

        for(int i = 0; i < 256; ++i)
            if( a[i] > b[i])
                return false;

        return true;
    }
    
    void calculate(string s, int* cm) {
        int size = s.size();
        for(int i = 0; i < size; ++i)
            cm[((int)s.at(i))]++;
    }
};



void test(string r, string m)
{
    cout << "input: r=" << r << ", m=" << m << "; output: ";
    bool rr = Solution().canConstruct(r, m);
    cout << rr << ";" << endl;
}

int main(void)
{
    test("aa", "aab");
}

// Result 
//
// 2022-11-25: Runtime 41ms 17.75% Memory 9.3MB 7.6%, https://leetcode.com/problems/ransom-note/submissions/849522516/
// 2023-02-22: Runtime 7ms 97.69% Memory 9.3MB 6.90%, https://leetcode.com/problems/ransom-note/submissions/902952827/

