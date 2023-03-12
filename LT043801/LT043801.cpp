#include <lt_help/lt.h>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        if( s_len < p_len )
            return {};
        vector<int> pc(26, 0), sc(26, 0), rst;
        count(pc, p, 0, p_len);
        count(sc, s, 0, p_len);
        if( is_equal(pc, sc) )
            rst.push_back(0);        
        for(int pos = 0; pos < s_len - p_len; ++pos )
        {   sc[s.at(pos) - 'a']--;
            sc[s.at(pos+p_len) - 'a']++;
            if( is_equal(pc, sc) )
                rst.push_back(pos+1); 
        }
        return rst;
    }
    
    bool is_equal(vector<int>& a, vector<int>& b) {
        int size = a.size();
        for(int i = 0;i < size; ++i)
            if( a[i] != b[i] )
                return false;
        return true;
    }
    
    void count(vector<int>& count, string& s, int pos, int len) {
        for(int i = 0; i < len; ++i)
        {   char c = s.at(pos+i);
            count[c-'a']++;
        }
    }
};



void test(string s, string p)
{
    cout << "input: s=" << s << ", p=" << p;
    vector<int> r = Solution().findAnagrams(s, p);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test("cbaebabacd", "abc");
}


// Result 
//
// 2023-03-11: Runtime 16ms 51.54% Memory 8.7MB 41.93%, https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/913280370/



