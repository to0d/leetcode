#include <lt_help/lt.h>



class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if((s1.size() + s2.size()) != s3.size()) return false;
        if((toXOR(s1) ^ toXOR(s2)) != toXOR(s3)) return false;
        
        return isInterleave(s1,s2,s3,0,0,0);
    }
    
    bool isInterleave(string& s1, string& s2, string& s3, int pos1, int pos2, int pos3)
    {
        // cout << "isInterleave: s1="<<s1 << ",s2="<<s2 << ",s3=" << s3 << endl;
        if( pos1 == s1.size())
             return isInterleave(s2,s3,pos2,pos3);
         
        if( pos2 == s2.size() )
             return isInterleave(s1,s3,pos1,pos3); 
        
        int a = s1[pos1];
        int b = s2[pos2];
        int c = s3[pos3];
        
        if( a == c && isInterleave(s1,s2,s3, pos1+1,pos2,pos3+1))
            return true;
        
        if( b == c && isInterleave(s1,s2,s3, pos1,pos2+1,pos3+1))
            return true;
        
        return false;   
    }
    
    bool isInterleave(string& s1, string& s2, int pos1, int pos2)
    {
        int count = s1.size() - pos1;
        for( int i = 0;i < count; ++i )
            if( s1[pos1+i] != s2[pos2+i] )
                return false;
            
        return true;
    }
    
    char toXOR(string& s)
    {
        char x = 0;
        for( char c : s)
            x^= c;
        return x;
    }
};
            


void test(string s1, string s2, string s3)
{
    cout << "input: s1=" << s1 << ", s2=" << s2 << ", s3=" << s3;
    bool r = Solution().isInterleave(s1, s2 ,s3);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test("aabcc", "dbbca" , "aadbbbaccc");
}

// Result 
//
// 2022/11/23
//      Time Limit Exceeded