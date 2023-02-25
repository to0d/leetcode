#include <lt_help/lt.h>




class Solution {
public:

    int evalRPN(vector<string>& tokens) 
    {   
        if( tokens.empty() )
             return 0;
         
        for( auto& t : tokens)
        {
            int val = 0;
            if( t.size() == 1 && isOp(t[0]))
            {
                int a = pop();
                int b = pop();
                
                switch( t[0] )
                {
                    case '+':
                        val = b + a;
                        break;
                    case '-':
                        val = b - a;
                        break;
                    case '*':
                        val = b * a;
                        break;
                    case '/':
                        val = b / a;
                        break;                        
                }
            }                
            else
                sscanf(t.c_str(), "%d", &val);
            
            push(val);
        }
        
        return pop();
    }
    
private:

    bool isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
    void push(int val) { numStack.push(val); }
    int pop()
    {
        int val = numStack.top();
        numStack.pop();
        return val;
    }
    
    stack<int>  numStack;
};

   
   
void test(vector<string>& tokens)
{
    cout << "input: ";
    outputVector(tokens);
    int r = Solution().evalRPN(tokens);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    vector<string> tokens = {"2","1","+","3","*"};
    test(tokens);
}

// Result 
//
// 2022/11/21
//      Runtime Error
//      ["-128","-128","*","-128","*","-128","*","8","*","-1","*"]