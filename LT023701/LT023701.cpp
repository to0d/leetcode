#include <lt_help/lt.h>

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        node->val  = next->val;
        node->next = next->next;
        // delete next;
    }
};



int main(void)
{
    ListNode* head = makeList(4, 4,5,1,9);
    cout << "input: ";
    outputList(head);
    ListNode* node = head->next;
    Solution().deleteNode(node);
    cout << "; output: ";
    outputList(head);
    cout << ";" << endl;
}

// Result 
//
// 2022-11-21: Runtime 36ms 6.71% Memory 7.7MB 69.93%, https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/847524615/
// 2023-02-22: Runtime 14ms 51.94% Memory 7.7MB 19.47%, https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/902725418/
