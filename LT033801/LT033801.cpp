#include <lt_help/lt.h>

class Solution {
public:
    Solution(){
        m_bits.push_back(0);
        m_bits.push_back(1);
    }

    vector<int> countBits(int num) {
        for(int k = m_bits.size(); k <= num; k*=2 )
        {   int m = std::min(k, num-k+1);
            for(int i=0; i < m; ++i)
                m_bits.push_back(m_bits.at(i)+1);
        }
        vector<int> r;
        for(int i = 0; i <= num; ++i)
            r.push_back(m_bits[i]);
        
        return r;
    }
    
    vector<int> m_bits;
};



void test(int num)
{
    cout << "input: " << num;
    vector<int> r = Solution().countBits(num);
    cout << "; output: "; 
    outputVector(r);
    cout << endl;
}


int main(void)
{ 
    test(5);
}

// Result 
//
// 2022-11-21: Runtime 9ms 43.70% Memory 8.5MB 23.78%, https://leetcode.com/problems/counting-bits/submissions/847200630/
// 2023-02-22: Runtime 7ms 55.26% Memory 9.5MB 24.13%, https://leetcode.com/problems/counting-bits/submissions/902758138/


