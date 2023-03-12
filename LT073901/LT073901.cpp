#include <lt_help/lt.h>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> st;
        vector<int> res(size,0);
        for(int i=0;i<size;i++) {
            while(!st.empty()&& temperatures[st.top()] < temperatures[i]) {
                int last = st.top(); st.pop();
                res[last] = i - last;
            }
            st.push(i);
        }
        return res;
    }
};



void test(vector<int> temperatures) {
    cout << "input: ";
    outputVector(temperatures);
    auto r = Solution().dailyTemperatures(temperatures);
    cout << "; output: " ;
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test({73,74,75,71,69,72,76,73});
}

// Result 
//
// 2023-03-11: Runtime 208ms 72.41% Memory 103.1MB 48.20%, https://leetcode.com/problems/daily-temperatures/submissions/912987248/, https://leetcode.com/problems/daily-temperatures/solutions/2926078/c-stacks-nge-easy-to-understand/



