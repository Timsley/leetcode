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
/*
**  This solution : The head point to head, not the first element
*/
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

    while(q)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }

    head->next = NULL;
    head = p;

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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *head;
    struct ListNode *p, *q;
    struct ListNode *pHead;

    p = l1;
    q = l2;
    pHead = head;

    if(p->val <= q->val)
    {
        head = p;
        p = p->next;
    }
    else
    {
        head = q;
        q = q->next;
    }

    while(p && q)
    {
        if(p->val <= q->val)
        {
            pHead->next = p;
            p = p->next;
        }
        else
        {
            pHead->next = q;
            q = q->next;
        }
        pHead = pHead->next;
    }

    if(p)
        pHead->next = p;
    else if(q)
        pHead->next = q;

    return head->next ;

}

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
    struct ListNode * retNode;
    struct ListNode * head= (struct ListNode *)malloc(sizeof(struct ListNode));

    for(i=1; i<=11; i++)
    {
        linked_list_insert(i, head);
    }
    
    struct ListNode * head2= (struct ListNode *)malloc(sizeof(struct ListNode));
    head2->val = 5;
    struct ListNode * head3= (struct ListNode *)malloc(sizeof(struct ListNode));
    head3->val = 9;

    head2->next = head3;
    head3->next = NULL;

    //for(i=5; i<=13; i++)
    {
    //    linked_list_insert(i, head2);
    }

    head = head->next;  // let the head point to the first element
    
    //head2 = head2->next;  // let the head point to the first element

    retNode = mergeTwoLists(head, head2);
    linked_list_traverse(retNode);
    
    //retNode = link_list_find_mid_ele(head);
    //printf("The mid ele is %d\n", retNode->val);

    //linked_list_traverse(retNode);
}
