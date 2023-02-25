#include <lt_help/lt.h>



class Solution {
    
public:
    
    int compareVersion(string version1, string version2) {
        
        int v1 = 0;
        int v2 = 0;     
        size_t pos1 = 0;
        size_t pos2 = 0;  

        while( (pos1 < version1.size() || pos2 < version2.size()) && v1 == v2)
        {   v1 = nextNumber(version1, pos1);
            v2 = nextNumber(version2, pos2);
        }
        
        return v1 > v2 ? 1 : ( v1 < v2 ? -1 : 0 );
    }
    
    int nextNumber(string& v, size_t& pos)
    {
        int num = 0;
        char c  = 0;
        
        while( pos < v.size() && (c = v.at(pos)) != '.')
        {   ++pos;
            num = num * 10 + (c - '0');
        }

        if( c == '.' )
            ++pos;

        return num;
    }
};
    


void test(string version1, string version2)
{
    cout << "input: version1=" << version1 << ", version2=" << version2;  
    int r = Solution().compareVersion(version1, version2);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test("1.01", "1.001");
}

// Result 
//
// 2022-11-19: Runtime 0ms 100% Memory 6.2MB 76.44%, https://leetcode.com/problems/compare-version-numbers/submissions/846352707/

