#include <lt_help/lt.h>
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* last = NULL;

    while( head != NULL )
    {   struct ListNode* next = head->next;
        head->next = last;
        last = head;
        head = next;
    }

    return last;
}



void test(struct ListNode* list)
{
    printf("input: ");
    outputList(list);
    struct ListNode* r = reverseList(list);
    printf("; output: ");
    outputList(r);
    printf("\n");
}

int main(void)
{
    test(makeList(5,1,2,3,4,5));
}

// Result 
//
// 2022-11-08: Runtime 4ms 46.48% Memory 7.7MB 6.21%, https://leetcode.com/problems/reverse-linked-list/submissions/839079778/
// 2023-02-16: Runtime 0ms 100% Memory 6.6MB 19.80%, https://leetcode.com/problems/reverse-linked-list/submissions/899180480/
