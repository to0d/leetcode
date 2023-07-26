#include <lt_help/lt.h>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits = {0};
        for( int i = 1; i <= n ; ++i )
            bits.push_back( bits[i/2] + (i%2==0? 0 : 1) ); // f(2n+1) = f(n)+1, f(2n) = f(n)
        return bits;
    }
};


void test(int num)
{
    cout << "input: " << num;
    vector<int> r = Solution().countBits(num);
    cout << "; output: "; 
    outputVector(r);
    cout << endl;
}

// Old solution: 
//
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> bits;        
//         bits.push_back(0);
//         for(int k = bits.size(); k <= num; k*=2 )
//         {   int m = std::min(k, num-k+1);
//             for(int i=0; i < m; ++i)
//                 bits.push_back(bits.at(i)+1);
//         }
//         return bits;
//     }
// };

int main(void)
{ 
    test(5);
}

// Result 
//
// 2022-11-21: Runtime 9ms 43.70% Memory 8.5MB 23.78%, https://leetcode.com/problems/counting-bits/submissions/847200630/
// 2023-02-22: Runtime 7ms 55.26% Memory 9.5MB 24.13%, https://leetcode.com/problems/counting-bits/submissions/902758138/
// 2023-03-12: Runtime 3ms 96.29% Memory 8.5MB 36.96%, https://leetcode.com/problems/counting-bits/submissions/913486516/
// 2023-07-26: Runtime 0ms 100% Memory 8.01MB 24.04%, https://leetcode.cn/problems/counting-bits/submissions/450333430/


