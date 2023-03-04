#include <lt_help/lt.h>

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int v = 0;
        for(; head != NULL ; head = head->next)
            v = v << 1 | head->val;
        return v;
    }
};



void test(ListNode* head)
{
    cout << "input: ";
    outputList(head);
    int r = Solution().getDecimalValue(head);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeList(3,1,0,1));
}


// Result 
//
// 2022-12-12: Runtime 3ms 52.89% Memory 8.2MB 70.25%, https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/858691183/
// 2023-03-04: Runtime 0ms 100% Memory 8.2MB 95.52%, https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/908963531/



