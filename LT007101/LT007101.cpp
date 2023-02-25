#include <lt_help/lt.h>

class Solution {
public:
    string simplifyPath(string path) {
        if( path.empty() )
             return "";
         
        deque<string> path_stack;
        int  path_length = 0;
        bool abs_path = false;
        string name;

        if( path[0] == '/' )
        {   abs_path = true;
            path_length++;
        }
        
        for(; path_length < path.size() ; ++path_length)
        {   char c = path[path_length];
            if( c == '/' )
            {   if( !name.empty() )
                {   if( name == ".." )
                    {   if( !path_stack.empty())
                            path_stack.pop_back();
                    }
                    else if( name != "." )
                        path_stack.push_back(name);
                    name.clear();
                }
            }
            else
                name.push_back(c);
        }
        
        if( !name.empty() )
        {   if( name == ".." )
            {   if( !path_stack.empty())
                    path_stack.pop_back();
            }
            else if( name != "." )
                path_stack.push_back(name);       
        }
        
        string newPath;
        if( abs_path )
            newPath.push_back('/');
        
        while( !path_stack.empty() )
        {   auto pn = path_stack.front();
            path_stack.pop_front();
            newPath += pn;
            if( !path_stack.empty() )
                 newPath.push_back('/');
        }
        
        return newPath;
    }
};



void test(string path)
{
    cout << "input: " << path << "; output: "; 
    string r = Solution().simplifyPath(path);
    cout << r << ";" << endl;
}

int main(void)
{
    test("/home/");
    test("/../");
    test("/home//foo/");
}

// Result 
//
// 2022-11-19: Runtime 7ms 62.69% Memory 7.5MB 91.51%, https://leetcode.com/problems/simplify-path/submissions/846153298/
// 2023-02-18: Runtime 4ms 83.40% Memory 7.5MB 93.85%, https://leetcode.com/problems/simplify-path/submissions/900092020/



