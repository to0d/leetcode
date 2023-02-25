#include <lt_help/lt.h>

class Solution {  
public:
    string countAndSay(int n) {
         if( n == 1) 
             return "1";
        
         vector<pair<int,int>> v1,v2;  
         vector<pair<int,int>> *pv1 = &v1, *pv2 = &v2;

         push_vec(v1, 1);
         for( int j = 0; j < n - 1 ; ++j )
         {  (*pv2).clear();
            for( auto& p : *pv1 )
            {   push_vec(*pv2, p.second);
                push_vec(*pv2, p.first);
            }
            auto* pt = pv2;
            pv2 = pv1;
            pv1 = pt;
         }

         string str;
         for( auto& p : *pv1 )
         {  int count = p.second;
            int val = p.first;
            for( int j = 0; j < count; ++j)
                str.push_back( '0'+ val);
         }

         return str;
    }

    void push_vec(vector<pair<int,int>>& vec, int v){
        if( v >= 10 )
        {   string str = to_string(v);
            int i = 0, m = 0;
            char c = str[0];

            while( i < str.size())
            {   if( c == str[i] )
                {   ++m;
                    ++i;
                }
                else
                {   push_vec(vec, m);
                    push_vec(vec, c - '0');
                    m = 0;
                    c = str[i];
                }
            }
            if( m > 0 )
            {   push_vec(vec, m);
                push_vec(vec, c - '0');
            }
        }
        else if( vec.empty() || vec[vec.size() - 1].first != v )
            vec.push_back(make_pair(v, 1));
        else
            vec[vec.size() - 1].second++;
    }
};



void test(int n)
{
    cout << "input: " << n << "; output=";
    string r = Solution().countAndSay(n);
    cout << r << ";" << endl;
}

int main(void)
{
    test(1);
    test(4);
}

// Result 
//
// 2022-11-16: Runtime 7ms 76.87% Memory 6.9MB 38.97%, https://leetcode.com/problems/count-and-say/submissions/844551294/
// 2023-02-17: Runtime 7ms 76.42% Memory 7MB 35.55%, https://leetcode.com/problems/count-and-say/submissions/899508875/

