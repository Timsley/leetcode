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

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *head;
    struct ListNode *ret;

    if(!l1 && l2)
        return l2;
    if(l1&&!l2)
        return l1;
    if(!l1 && !l2)
        return NULL;
    
    if(l1->val <= l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }
    
    ret = head;
    
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            head->next = l1;
            l1 = l1->next;
        }
        else
        {
            head->next = l2;
            l2 = l2->next;
        }

        head->next->next = NULL;
        head = head->next;        
    }

    if(l1)
        head->next = l1;
    else if(l2)
        head->next = l2;

    return ret;
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

/***************************************************************************************
*****                                   No. 328     Odd Even Linked List
*****       Given a singly linked list, group all odd nodes together followed by the even nodes. Please note 
*****       here we are talking about the node number and not the value in the nodes.
*****       You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*****       Example:
*****       Given 1->2->3->4->5->NULL,
*****       return 1->3->5->2->4->NULL.
*****
*****       Note:
*****       The relative order inside both the even and odd groups should remain as it was in the input. 
*****       The first node is considered odd, the second node even and so on ...
****************************************************************************************/
struct ListNode* oddEvenList(struct ListNode* head) 
{
    struct ListNode *p, *q, *t, *evenHead;
    int count = 1;
    
    if(!head || !head->next || !head->next->next)
        return head;

    p = head;
    q = head->next;
    evenHead = head->next;
    t = head->next->next;

    while(t)
    {
        if(1 == count)
        {
            count = 2;
            p->next = t;
            p = t;
        }
        else if(2 == count)
        {
            count = 1;
            q->next = t;
            q = t;
        }
        t = t->next;
    }

    q->next = NULL;
    p->next = evenHead;
    
    return head;
}

/***************************************************************************************
*****                             No. 83      Remove Duplicates from Sorted List
*****       Given a sorted linked list, delete all duplicates such that each element appear only once.
*****       For example,
*****       Given 1->1->2, return 1->2.
*****       Given 1->1->2->3->3, return 1->2->3.
****************************************************************************************/
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode * p;
    p = head;

    if(!head)
        return NULL;

    while(p && p->next)
    {
        if(p->val == p->next->val)
            p->next = p->next->next;
        else
            p = p->next;
    }

    return head;
}

void link_list_main_test(void)
{
    //int i =0;
    struct ListNode * l1_head, * l2_head;
    struct ListNode * retNode;
    struct ListNode * l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    linked_list_insert(0, l1);    
    linked_list_insert(1, l1);   
    linked_list_insert(1, l1);
    linked_list_insert(3, l1);
    linked_list_insert(3, l1);
    linked_list_insert(3, l1);
    linked_list_insert(4, l1);
    linked_list_insert(5, l1);
    l1_head = l1->next;

    
    struct ListNode * l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    linked_list_insert(2, l2);
    linked_list_insert(5, l2);
    linked_list_insert(9, l2);
    linked_list_insert(13, l2);
    l2_head = l2->next;

    //for(i=5; i<=13; i++)
    {
    //    linked_list_insert(i, head2);
    }
    linked_list_traverse(l1_head);
    //linked_list_traverse(l2_head);

    printf("\n\n");
    
    
    //head2 = head2->next;  // let the head point to the first element

  // retNode = mergeTwoLists(l1_head, l2_head);
    retNode = deleteDuplicates(l1_head);
    linked_list_traverse(retNode);
    
    //retNode = link_list_find_mid_ele(head);
    //printf("The mid ele is %d\n", retNode->val);

    //linked_list_traverse(retNode);
}
