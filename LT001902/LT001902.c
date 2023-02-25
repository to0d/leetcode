#include <lt_help/lt.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode** array = malloc( (n+1)*sizeof(struct ListNode* ) );
    memset(array, 0, (n+1)*sizeof(struct ListNode*));
    
    int i = 0;
    struct ListNode* node = head;
    for( ;node != NULL; i %= n+1, node = node->next)
        array[i++] = node;
    
    struct ListNode* previous = array[i%(n+1)];
    struct ListNode* target = array[(i+1)%(n+1)];
    
    if( previous == NULL )
        head = target->next;
    else
        previous->next = target->next;
    
    free(target);
    return head;
}


void test(struct ListNode* list, int n)
{
    printf("input: n=%d, list=", n); 
    outputList(list);
    struct ListNode* r = removeNthFromEnd(list, n);
    printf("; output: ");
    outputList(r);
    printf("\n");
}

int main(void)
{
    test(makeList(5,1,2,3,4,5), 2);
}

// Result 
//
// 2022-11-03: Runtime 0ms 100% Memory 6.1MB 37.20%, https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/836105060/
// 2023-02-15: Runtime 0ms 100% Memory 6.1MB 37.6%, https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/898558384/


