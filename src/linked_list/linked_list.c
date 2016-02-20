#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "typedef.h"
#include "linked_list.h"



int linked_list_insert(int element, struct ListNode * pList)
{
    LINKED_LIST_CHK_FAIL(pList, LISTR_FAIL);
    
    struct ListNode * pTemp = pList;
    
    while(pTemp->next  != NULL)
    {
       pTemp = pTemp->next;
    }
    
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(!node)
    {
        printf("link_list_insert_at_tail malloc failed! \n");
        return LISTR_FAIL;
    }
    
    node->val= element;
    node->next = NULL;
    
    pTemp->next= node;   
    
   return LISTR_OK;
}
#if 0
int linked_list_insert(int element, struct ListNode * pList)
{
    if(!pList)
        return LISTR_FAIL;

    
}
#endif
void linked_list_traverse(struct ListNode * pList)
{    
    struct ListNode * pTemp = pList;

    while(pTemp != NULL)
    {
        printf("node->element : %d\n", pTemp->val);
        pTemp = pTemp->next;
    }
}
#if 0
struct ListNode* reverseList(struct ListNode* head) 
{
    if(!head || !head->next)
    {
        return head;
    }

    if(!head->next->next)
    {
        return head;
    }
    
    struct ListNode* p = head->next;
    struct ListNode* q = head->next->next;
    struct ListNode* t;
    
    while(q != NULL)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }

    head->next->next = NULL;
    head->next = p;

    return head;
}
#endif

/*
**  This solution : The head point to the first element, not the head node
*/
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* t;
    struct ListNode* p, * q;

    if(!head || !head->next)
        return head;

    p = head; 
    q = head->next;
        printf("p val =%d\n", p->val);
        printf("q val =%d\n", q->val);

    while(q)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
        printf("p val =%d\n", p->val);
    }

    head->next = NULL;
    head = p;
    printf("head val =%d\n", head->val);
    printf(" head->next val =%d\n",  head->next->val);

    return head;
}

#if 0
bool isPalindrome(struct ListNode* head) 
{
    struct ListNode* p = head;
    struct ListNode* q;
    int listSize = 0;

    if(!head)
        return 0;

    if(head->next == NULL)
        return 1;
    
    while(p->next != NULL)
    {
        listSize++;
        p = p->next;
    }

    q = p;
}
#endif

struct ListNode* link_list_find_mid_ele(struct ListNode* head)
{
    struct ListNode* fast, *slow;

    fast = head;
    slow = head;

    if(!head)
        return NULL;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}


void link_list_main_test(void)
{
    int i =0;
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));

    //for(i=1; i<=2; i++)
    {
    //    linked_list_insert(i, testList);
    }
    head->val = 1;
    
    struct ListNode * testList2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    testList2->val = 2;

    head->next = testList2;
    testList2->next = NULL;
    //struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode));
    //list = reverseList(testList);

    linked_list_traverse(head);

    struct ListNode * retNode;
    struct ListNode * p = head;
// retNode = link_list_find_mid_ele(testList);
    retNode = reverseList(head);
//printf("head val =%d\n", head->val);
//printf(" head->next val =%d\n",  head->next->val);

printf("\n\n");
   // linked_list_traverse(p);

    //printf("The mid ele is %d\n", retNode->val);
}
