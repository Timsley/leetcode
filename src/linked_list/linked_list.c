#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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

struct ListNode* linked_list_find_mid_ele(struct ListNode* head)
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

#if 0
/***************************************************************************************
*****                                   206. Reverse Linked List
*****       Reverse a singly linked list.
*****       Hint:
*****       A linked list can be reversed either iteratively or recursively. Could you implement both?
****************************************************************************************/
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

/***************************************************************************************
*****                                   206. Reverse Linked List
*****       Reverse a singly linked list.
*****       Hint:
*****       A linked list can be reversed either iteratively or recursively. Could you implement both?
****************************************************************************************/
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

/***************************************************************************************
*****                                   234. Palindrome Linked List
*****       Given a singly linked list, determine if it is a palindrome.
*****       Follow up:
*****       Could you do it in O(n) time and O(1) space?
****************************************************************************************/
bool isPalindrome(struct ListNode* head) 
{
    struct ListNode * midNode;
    struct ListNode *leftList, *rightList;

    if(!head || !head->next)
        return true;
    
    leftList = head;    
    midNode = linked_list_find_mid_ele(head);

    rightList = reverseList(midNode);

    while(leftList && rightList)
    {
        if(leftList->val != rightList->val)
            return false;
        leftList = leftList->next;
        rightList = rightList->next;
    }

    return true;
}

/***************************************************************************************
*****                                   21. Merge Two Sorted Lists
*****       Merge two sorted linked lists and return it as a new list.
*****       The new list should be made by splicing together the nodes of the first two lists.
****************************************************************************************/
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

/***************************************************************************************
*****                             No. 160      Intersection of Two Linked Lists
*****       Write a program to find the node at which the intersection of two singly linked lists begins.
*****       Notes:
*****       If the two linked lists have no intersection at all, return null.
*****       The linked lists must retain their original structure after the function returns.
*****       You may assume there are no cycles anywhere in the entire linked structure.
*****       Your code should preferably run in O(n) time and use only O(1) memory.
****************************************************************************************/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *LA, *LB;    
    struct ListNode *h1, *h2;
    int lenA=0, lenB=0, step=0;

    if(!headA || !headB)
        return NULL;

    LA = headA;
    LB = headB;
    
    while(LA)
    {
        lenA++;
        LA = LA->next;
    }
    
    while(LB)
    {
        lenB++;
        LB = LB->next;
    }

    if(lenA >= lenB)
    {
        step = lenA - lenB;
        h1 = headA;
        h2 = headB;
    }
    else
    {
        step = lenB - lenA;
        h1 = headB;
        h2 = headA;
    }

    while(h1 && step)
    {
        step--;
        h1 = h1->next;
    }

    while(h1 && h2)
    {
        if(h1->val == h2->val)
            return h1;

        h1 = h1->next;
        h2 = h2->next;
    }
    
    return NULL;
}

/***************************************************************************************
*****                             203. Remove Linked List Elements
*****       Remove all elements from a linked list of integers that have value val.
*****       Example
*****       Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
*****       Return: 1 --> 2 --> 3 --> 4 --> 5
****************************************************************************************/
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode * p;
    struct ListNode * q;
    struct ListNode * ret;
    
    if(!head)
        return NULL;
    
    p = head;

    while(p && (p->val == val))     // find the head of the return list
    {
        p = p->next;
    }

    if(!p)
        return NULL;

    q = p;
    ret = q;                                   // keep the first element of the return list

    p = p->next;
    
    while(p)
    {
        if(p->val != val)                 // if val is not equal the p->val, save it to the return list
        {
            q->next = p;
            q = p;
        }

        p = p->next;
    }

    q->next =NULL;

    return ret;
}


/***************************************************************************************
*****                             24. Swap Nodes in Pairs
*****       Given a linked list, swap every two adjacent nodes and return its head.
*****       For example,
*****       Given 1->2->3->4, you should return the list as 2->1->4->3.
*****       Your algorithm should use only constant space. You may not modify the values in the list, 
*****       only nodes itself can be changed.
****************************************************************************************/
struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode *p, *q, *right, *left;
    struct ListNode * ret;
    
    if(!head || !head->next)
        return head;

    p = head;
    q = p->next;

    if(p && q)
        ret = q;

    while(p && q)
    {
        right = q->next;
        q->next = p;
        left = p;
        p->next = right;
        p = right;
        
        if(!right || !right->next)
            break;
        
        if(right->next)
        {
            q = p->next;
            left->next = q;
        }
    }

    return ret;
}


/***************************************************************************************
*****                             237. Delete Node in a Linked List
*****       Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
*****       Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
*****       the linked list should become 1 -> 2 -> 4 after calling your function.
****************************************************************************************/
void deleteNode(struct ListNode* node) 
{
    if(!node || !node->next)
        return;

    node->val = node->next->val;
    node->next = node->next->next;
}


/***************************************************************************************
*****                             2. Add Two Numbers
*****       You are given two linked lists representing two non-negative numbers. 
*****       The digits are stored in reverse order and each of their nodes contain a single digit. 
*****       Add the two numbers and return it as a linked list.

*****       Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*****       Output: 7 -> 0 -> 8
****************************************************************************************/
void addNodeToList(struct ListNode* list)
{
    struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(node)
    {
        node->val = 1;
        node->next = NULL;
        list->next = node;
    }
}

void addTailNodeToList(struct ListNode* list, bool fgADD)
{
    struct ListNode* temp;

    while(list)
    {
        if(true == fgADD)
        {
            list->val = list->val + 1;
            fgADD = false;
            if(list->val >= 10)
            {
                list->val = list->val - 10;
                fgADD = true;
            }
            else
                fgADD = false;
            
            temp = list;
            list = list->next;
            
             if(!list)
            {
                if(fgADD==true)
                    addNodeToList(temp);

                return;
            }
        }
        else
            return;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    bool fgADD = false;
    struct ListNode *l1_head, *l2_head;
    struct ListNode *last_point;
        
    if(!l1)        return l2;
    if(!l2)        return l1;

    l1_head = l1;    l2_head = l2;

    while(l1 && l2)
    {
        if(true == fgADD)
            l1->val = l2->val = l1->val + l2->val + 1;
        else
            l1->val = l2->val = l1->val + l2->val;

        if(l1->val >= 10)
        {
            l1->val = l2->val = l1->val - 10;
            fgADD = true;
        }
        else
            fgADD = false;

        last_point = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1)
    {
        addTailNodeToList(l1, fgADD);
        return l1_head;
    }
    
    if(l2)
    {
        addTailNodeToList(l2, fgADD);
        return l2_head;
    }

    if(true == fgADD)
        addNodeToList(last_point);

    return l1_head;
}

/***************************************************************************************
*****                             141. Linked List Cycle
*****       Given a linked list, determine if it has a cycle in it.

*****       Follow up:
*****       Can you solve it without using extra space?
****************************************************************************************/
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast, *slow;

    fast = head;
    slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return true;
    }

    return false;
}

/***************************************************************************************
*****                             142. Linked List Cycle II
*****       Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*****       Note: Do not modify the linked list.

*****       Follow up:
*****       Can you solve it without using extra space?
****************************************************************************************/
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *fast, *slow;
    bool fgHasCycle = false;

    if(!head)
        return NULL;

    fast = head;
    slow = head;
    
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            fgHasCycle = true;
            break;
        }
    }

    if(true == fgHasCycle)
    {
        fast = head;
        while(fast)
        {
            if(fast == slow)
                return fast;
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    return NULL;
}

/***************************************************************************************
*****                             86. Partition List 
*****       Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
*****       
*****       You should preserve the original relative order of the nodes in each of the two partitions.
*****       
*****       For example,
*****       Given 1->4->3->2->5->2 and x = 3,
*****       return 1->2->2->4->3->5.
****************************************************************************************/
struct ListNode* partition(struct ListNode* head, int x) 
{
    struct ListNode *leftHead, *rightHead, *left, *right;
    struct ListNode *ret;

    if(!head)
        return NULL;
    
    leftHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    rightHead = (struct ListNode *)malloc(sizeof(struct ListNode));

    left = leftHead;
    right = rightHead;

    while(head)
    {
        if(head->val < x)
        {
            left->next = head;
            left = left->next;
        }
        else
        {
            right->next = head;
            right = right->next;
        }
        head = head->next;
    }

    right->next = NULL;
    left->next = rightHead->next;

    ret = leftHead->next;
    
    if(leftHead)
        free(leftHead);
    if(rightHead)
        free(rightHead);

    return ret;
}

/***************************************************************************************
*****                             92. Reverse Linked List II 
*****       Reverse a linked list from position m to n. Do it in-place and in one-pass.
*****       
*****       For example:
*****       Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*****       
*****       return 1->4->3->2->5->NULL.
*****       
*****       Note:
*****       Given m, n satisfy the following condition:
*****       1 = m = n = length of list.
****************************************************************************************/
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) 
{
    struct ListNode *p, *q, *t;
    struct ListNode *h1, *h2;           // h1 : remember the pointer before m'th; h2 : remember the m'th pointer
    int count = 1;

    if(!head)
        return NULL;

    p = head;
    h1 = p;
    
    while(p && count<m)
    {
        h1 = p;
        p = p->next;
        count++;
    }

    if(!p)
        return head;
    else
        q = p->next;

    h2 = p;
    
    while(q && count<n)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
        count++;
    }

    if(h1 == h2)                // if m=1
    {
        h1->next = q;
        head = p;
    }
    else
    {
        h1->next = p;
        h2->next = q;
    }

    return head;
}

/***************************************************************************************
*****                             61. Rotate List 
*****       Given a list, rotate the list to the right by k places, where k is non-negative.
*****       
*****       For example:
*****       Given 1->2->3->4->5->NULL and k = 2,
*****       return 4->5->1->2->3->NULL.
****************************************************************************************/
struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    struct ListNode *p, *t, *q, *ret;
    int length = 0;

    if(!head)
        return NULL;

    p = head;

    while(p)
    {
        p = p->next;
        length++;
    }

    p = head;
    
    if(k>length)
        k = length - k%length;
    else
        k = (length-k)%length;

    while(p && k>1)
    {
        q = p;
        p = p->next;
        k--;
    }

    if(!p->next  || k == 0)
        return head;
    
    ret = t = p->next;
    
    p->next = NULL;

    while(t)
    {
        q = t;
        t = t->next;
    }

    q->next = head;
    
    return ret;
}

/***************************************************************************************
*****                             82. Remove Duplicates from Sorted List II
*****       Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
*****      
*****       For example,
*****       Given 1->2->3->3->4->4->5, return 1->2->5.
*****       Given 1->1->1->2->3, return 2->3.
****************************************************************************************/
struct ListNode* deleteDuplicates2(struct ListNode* head) 
{
    struct ListNode *p, *q, *ret;
    struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode));

    p = head;
    q = list;

    while(p)
    {
        if(p->next && (p->val == p->next->val))
        {
            while(p->next && (p->val == p->next->val))
            {
                p = p->next;
            }
        }
        else
        {
            q->next = p;
            q = p;
        }
        p = p->next;
    }

    if(q)
        q->next = NULL;

    ret = list->next;
    
    if(list)
        free(list);

    return ret;
}

void link_list_main_test(void)
{
    struct ListNode * l1_head;
//    struct ListNode * l2_head;
    struct ListNode * retNode;
    
    struct ListNode * l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    linked_list_insert(1, l1);   
    linked_list_insert(1, l1);    
    linked_list_insert(1, l1);   
    linked_list_insert(2, l1);
    l1_head = l1->next;

#if 0
    struct ListNode * l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    linked_list_insert(6, l2);       
    linked_list_insert(7, l2);       
    linked_list_insert(8, l2);       
    linked_list_insert(9, l2);       
    linked_list_insert(3, l2);       
    linked_list_insert(4, l2);       
    l2_head = l2->next;
 #endif   

    linked_list_traverse(l1_head);
    printf("\n");
    //linked_list_traverse(l2_head);

    printf("\n\n");

    retNode = deleteDuplicates2(l1_head);
    linked_list_traverse(retNode);

}
