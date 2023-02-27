#include <lt_help/lt.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
}; 

class Solution {
public:
    Node* copyRandomList(Node* head) { 
        if( head == NULL )
            return NULL;
        
        // insert a next node for each node in previous list
        Node* pCur = head;
        while( pCur != NULL )
        {   Node* pNext = pCur->next;
            Node* pNew = (struct Node*) malloc(sizeof(struct Node));
            pNew->val    = pCur->val;
            pNew->next   = pNext;
            pNew->random = NULL;
            pCur->next = pNew;
            pCur = pNext;
        }
        
        // set random pointer for each new node
        pCur = head;
        while( pCur != NULL )
        {   Node* pNew  = pCur->next;
            Node* pNext = pNew->next;
            if( pCur->random != NULL )
                pNew->random = pCur->random->next;               
            pCur = pNext;
        }

        // detach every new node to a list
        Node NewHead(0);
        Node* pNewHead = &NewHead;
        pCur = head;
        while( pCur != NULL )
        {   Node* pNew  = pCur->next;
            Node* pNext = pNew->next;
            pNewHead->next = pNew;
            pNewHead = pNew;
            pCur->next = pNext;
            pCur = pNext;
        }

        pNewHead->next = NULL;
        return NewHead.next;
    }
};

 

int main(void)
{
    printf("output: done\n");
}

// Result 
//
// 2022-11-06: Runtime 15ms 16.54% Memory 8.2MB 100%, https://leetcode.com/problems/copy-list-with-random-pointer/submissions/855115503/
// 2023-02-27: Runtime 11ms 53.5% Memory 11.3MB 30.42%, https://leetcode.com/problems/copy-list-with-random-pointer/submissions/905741610/




