#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

typedef int ElementType;

typedef struct QUEUE_T
{
    ElementType value;
    int length;
    struct QUEUE_T *next;
}QUEUE;

typedef struct QUEUE_T Node;

#define QUEUE_MAX_LEN 10

QUEUE * queue_create(void)
{
    QUEUE * queue = (QUEUE *)malloc(sizeof(QUEUE));
    if(NULL == queue)
    {
        printf("queue malloc fail\n");
        return NULL;
    }

    memset(queue, 0, sizeof(QUEUE));
    queue->length = 0;
    queue->next = NULL;
    
    return queue;
}

bool queue_is_empty(QUEUE *queue)
{
    return queue->next == NULL;
}

bool queue_is_full(QUEUE *queue)
{
    return queue->length == QUEUE_MAX_LEN;
}

ElementType queue_front(QUEUE *queue)
{
    QUEUE * q = queue;

    if(!q->next)
        return -1;
        
    while(q->next)
        q = q->next;

    return q->value;
}

ElementType queue_back(QUEUE *queue)
{
    return queue->next->value;
}

int queue_push(QUEUE *queue, ElementType elem)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(NULL == node)
    {
        printf("node malloc fail\n");
        return -1;
    }
    memset(node, 0, sizeof(Node));
    
    memcpy(&node->value, &elem, sizeof(ElementType));
    node->next = queue->next;
    
    queue->next = node;
    //queue->length++;

    return 0;
}

void queue_pop(QUEUE *queue)
{
    QUEUE *q,*temp;

    q = temp = queue;

    if(!queue || !queue->next)
        return;

    while(q->next)
    {
        temp = q;
        q = q->next;
    }

    temp->next = NULL;
    //queue->length--;
    
    free(q);     
}

#if 0
/* traverse from back to front */
void queue_traverse(QUEUE *queue)
{
    QUEUE * q = queue;
    
    if(!queue || !queue->next)
        return;
    
    while(q->next)
    {
        printf("value=%d\n", q->next->value);
        q = q->next;
    }
}
#endif

/***************************************************************************************
*****                             225. Implement Stack using Queues 
*****       
*****       Implement the following operations of a stack using queues.
*****       
*****       push(x) -- Push element x onto stack.
*****       pop() -- Removes the element on top of the stack.
*****       top() -- Get the top element.
*****       empty() -- Return whether the stack is empty.
*****       
*****       Notes:
*****       You must use only standard operations of a queue -- which means only push to back, 
*****       peek/pop from front, size, and is empty operations are valid.
*****       Depending on your language, queue may not be supported natively. You may simulate a queue by using
*****       a list or deque (double-ended queue), as long as you use only standard operations of a queue.
*****       You may assume that all operations are valid (for example, no pop or top operations 
*****       will be called on an empty stack).
****************************************************************************************/
typedef struct {
    QUEUE * queueA;
    QUEUE * queueB;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->queueA = queue_create();
    stack->queueB = queue_create();
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    while(!queue_is_empty(stack->queueA))
    {
        queue_push(stack->queueB, queue_front(stack->queueA));
        queue_pop(stack->queueA);
    }
    
    queue_push(stack->queueA, element);
    
    while(!queue_is_empty(stack->queueB))
    {
        queue_push(stack->queueA, queue_front(stack->queueB));
        queue_pop(stack->queueB);
    }
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    queue_pop(stack->queueA);
}

/* Get the top element */
int stackTop(Stack *stack) {
    return queue_front(stack->queueA);
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return queue_is_empty(stack->queueA);
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    if(stack)
    {
        free(stack->queueA);
        free(stack->queueB);
    }
}




void queue_main_test(void)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stackCreate(stack, 10);

    stackPush(stack, 1);
    stackPush(stack, 2);
    stackPush(stack, 3);
    stackPush(stack, 4);
    stackPop(stack);

    printf("top:%d\n", stackTop(stack));
    //queue_traverse(stack->queueA);
}
