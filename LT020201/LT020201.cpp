#include <lt_help/lt.h>

class Solution {
public:

    bool isHappy(int n) {
        if( n == 0 ) return false;
        if( n == 1 ) return true;
        
        int m = n;
        bool happy = false;
        unordered_set<int> visited;
        
        while( visited.count( m ) == 0 )
        {
            if( m == 1 )
            {   happy = true;
                break;
            }
                
            auto it = happyMap.find(m);
            if( it != happyMap.end() )
            {   happy = (*it).second;
                break;
            }
            
            visited.insert( m );
            
            int t = 0;
            for( ; m > 0 ; m /= 10 )
            {   int k = m % 10;
                t += k*k; 
            }

            m = t;
        }
        
        for( auto v : visited )
            happyMap[v] = happy;

        return happy;
    }
    
    unordered_map<int, bool> happyMap;
};



void test(long n)
{
    cout << "input: " << n << "; output: ";
    bool r = Solution().isHappy(n);
    cout << r << ";" << endl;
}

int main(void)
{
    test(19); 
    test(1999999999); 
}

// Result 
//
// 2022-11-21: Runtime 4ms 39.37% Memory 6.5MB 6.58%, https://leetcode.com/problems/happy-number/submissions/846973268/
// 2023-02-22: Runtime 4ms 38.78% Memory 6.7MB 6.74%, https://leetcode.com/problems/happy-number/submissions/902628893/


