#include <lt_help/lt.h>

//           |<-- a -->|
//   A:          a1 -> a2
//                      \ |<-- c -->|
//                        c1 -> c2 -> c3
//                      /            
//   B:     b1 -> b2 ->? b3
//          |<-- b -->|
//          
//          
//   la = length(A) = a + c;
//   lb = length(B) = b + c;
//   
//   Reverse list b
//   
//           |<-- a -->|
//   A:          a1 -> a2
//                      \ |<-- c -->|
//                        c1 -> c2 -> c3
//                      /             \
//   B:     b1 -> b2 -> b3             Tail
//          |<-- b -->| 
//
//   Now, iterate list A' 
//
//   lc = length(A') = a + b;
//   
//   So, you can get the value of "c":
//       
//      c = (la+lb-lc)/2;
//   
//   The intersect node should be at position c from tail. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* _reverseList(struct ListNode *head )
{
    struct ListNode * p1 = NULL;
    struct ListNode * p2 = head;
    struct ListNode * p3;
    while( p2->next != NULL )
    {   p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    p2->next = p1;
    return p2;
} 

struct ListNode* _travelList(struct ListNode *head, int* listLength)
{
    struct ListNode *tail = head;
    *listLength = 0;
    
    if( head == NULL )
    {   return NULL;
    } 
    
    while( tail->next != NULL )
    {   tail = tail->next;
        ++(*listLength);
    }
    
    return tail;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   
    if( headA == NULL || headB == NULL ) return NULL;
    if( headA == headB ) return headA;

    int alen, blen, clen;
    
    struct ListNode *TailA = _travelList(headA, &alen);
    struct ListNode *TailB = _travelList(headB, &blen);
    
    if( TailA != TailB )
       return NULL;
   
    struct ListNode * longHead  = alen>blen? headA : headB;
    struct ListNode * shortHead = alen>blen? headB : headA;
  
    _reverseList(longHead);
    _travelList(shortHead, &clen);
    
    int d = (alen + blen - clen) / 2;
    struct ListNode * target = TailA;
    
    while( d-- > 0 )
    {   target = target->next;
    }
    
    _reverseList(TailA);
 
    return target;
}


void test(struct ListNode *headA, struct ListNode *headB)
{
    printf("input: headA=");
    outputList(headA);
    printf(", headB=");
    outputList(headB);
    struct ListNode* r = getIntersectionNode(headA, headB);
    printf("; output: ");
    outputList(r);
    printf(";\n");
}

int main(void)
{
     test(makeList(5,4,1,8,4,5), makeList(6,5,6,1,8,4,5));
}

// Result 
//
// 2022-11-21: Runtime 41ms 76.34% Memory 14.1MB 12.30%, https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/847487044/


