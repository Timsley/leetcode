#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


typedef int ElemType;
//typedef char ElemType;

typedef struct STACK_T 
{
    ElemType value;
    struct STACK_T * next;
}STACK;

typedef struct STACK_T NODE;

STACK * stack = NULL;

STACK * stack_init(void)
{
    STACK * stack = (STACK *)malloc(sizeof(STACK));
    if(!stack)
    {
        printf("malloc stack fail\n");
        return NULL;
    }

    memset(stack, 0, sizeof(STACK));
    stack->next = NULL;

    return stack;
}

bool stack_is_empty(STACK * stack)
{
    return (stack->next == NULL);
}

ElemType stack_pop(STACK * stack)
{
    ElemType retValue;
    
    STACK * temp = NULL;
    
    if(!stack_is_empty(stack))
    {
        temp = stack->next;
        stack->next = stack->next->next;
        retValue = temp->value;
        free(temp);
    }
    else
    {
        printf("stack is empty\n");
        return 0;
    }

    return retValue;
}

int stack_push(STACK * stack, ElemType ele)
{
    NODE * node = (NODE *)malloc(sizeof(NODE));

    node->value = ele;
    node->next = stack->next;
    stack->next = node;

    return 0;
}

ElemType stack_top(STACK * stack)
{
    if(!stack_is_empty(stack))
    {
        return stack->next->value;
    }

    return (ElemType)(-1);
}

int stack_traverse(STACK * stack)
{    
    printf("\nStack have follow elements : \n");

    while(stack && stack->next)
    {
        printf("element=%d\n", stack->next->value);
        stack = stack->next;
    }

    return 0;
}



/***************************************************************************************
*****                             20. Valid Parentheses 
*****       Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*****       
*****       The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
****************************************************************************************/
bool isValid(char* s) 
{
    char * p = s;
    
    if(!p)
        return false;

    if(*(p+1) == '\0')
        return false;
    
    stack = stack_init();

    while(*p != '\0')
    {
        if( (*p == '(') ||(*p == '{') || (*p == '[') )
            stack_push(stack, *p);
        else if(*p == ')')
        {
            if('(' != stack_top(stack))
                return false;
            else 
                stack_pop(stack);
        }
        else if(*p == '}')
        {
            if('{' != stack_top(stack))
                return false;
            else 
                stack_pop(stack);
        }
        else if(*p == ']')
        {
            if('[' != stack_top(stack))
                return false;
            else 
                stack_pop(stack);
        }
        else 
            return false;

        p = p + 1;
    }

    if(true == stack_is_empty(stack))
        return true;
    else
        return false;
}


/***************************************************************************************
*****                             232. Implement Queue using Stacks
*****       Implement the following operations of a queue using stacks.
*****       push(x) -- Push element x to the back of queue.
*****       pop() -- Removes the element from in front of queue.
*****       peek() -- Get the front element.
*****       empty() -- Return whether the queue is empty.
*****       Notes:
*****       You must use only standard operations of a stack -- which means only push to top, peek/pop 
*****       from top, size, and is empty operations are valid.
*****       Depending on your language, stack may not be supported natively. You may simulate a stack 
*****       by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
*****       You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
****************************************************************************************/
typedef struct {
    STACK * stackA;
    STACK * stackB;
} Queue;

//Queue * queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->stackA = stack_init();
    queue->stackB = stack_init();
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    while(!stack_is_empty(queue->stackA))
    {
        stack_push(queue->stackB, stack_top(queue->stackA));
        stack_pop(queue->stackA);
    }

    stack_push(queue->stackA, element);

    while(!stack_is_empty(queue->stackB))
    {
        stack_push(queue->stackA, stack_top(queue->stackB));
        stack_pop(queue->stackB);
    }
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    stack_pop(queue->stackA);
}

/* Get the front element */
int queuePeek(Queue *queue) {
    return stack_top(queue->stackA);
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    return stack_is_empty(queue->stackA);
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    if(queue)
    {
        free(queue->stackA);
        free(queue->stackB);
    }
}



void stack_main_test(void)
{
    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queueCreate(queue, 10);
    queuePush(queue, 5);
    queuePush(queue, 1);
    queuePush(queue, 2);
    queuePush(queue, 3);
    queuePush(queue, 4);

    printf("front : %d\n", queuePeek(queue));
}
#if 0
void stack_main_test(void)
{
    int ret = 0;
    char str[] = "([])";
    //char str[] = "()[]{}";
    //char str[] = "()";
    //char str[] = "([)]";    
    //char str[] = "(]"; 
    //char str[] = "(";
    //char str[] = "((";
    
    ret = isValid(str);
    printf("ret=%d\n", ret);
}
#endif
