#include <lt_help/lt.h>

class Solution {
public:
    int evalRPN(vector<string>& tokens){   
        if( tokens.empty() )
             return 0;
        stack<int>  num_stack;
        for(string& t : tokens)
        {   int val = 0; char op;
            if( t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/'))
            {   int a = num_stack.top(); num_stack.pop();
                int b = num_stack.top(); num_stack.pop();
                switch( t[0] )
                {   case '+': val = b + a; break;
                    case '-': val = b - a; break;
                    case '*': val = b * a; break;
                    case '/': val = b / a; break;                        
                }
            }                
            else
                sscanf(t.c_str(), "%d", &val);
            num_stack.push(val);
        }
        return num_stack.top();
    }
};

   
void test(vector<string> tokens)
{
    cout << "input: ";
    outputVector(tokens);
    int r = Solution().evalRPN(tokens);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({"2","1","+","3","*"});
}

// Result 
//
// 2023-07-31: Runtime 8ms 89.18% Memory 11.46MB 38.51%, https://leetcode.cn/problems/evaluate-reverse-polish-notation/submissions/451871280/

