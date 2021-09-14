#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static STACK_PTR_t top = NULL;
static STACK_PTR_t createNode();
static void printStack();

bool_t isEmpty()
{
    return (top == NULL)? TRUE : FALSE;
}

void push(uint32_t value)
{
    if(isEmpty(top))
    {
        top = createNode();
        top->value = value;
        top->next = NULL;
    }
    else
    {
        STACK_PTR_t temp = createNode();
        temp->value = value;
        temp->next = top;
        top = temp;
    }
}

int32_t pop()
{
    STACK_PTR_t temp = top;
    uint32_t val = top->value;

    if(isEmpty(top))
    {
        return -1;
    }
    else
    {
        top = top->next;
        free(temp);
    }

    return val;
}

int32_t peek()
{
    if(isEmpty(top))
        return -1;
    else
        return top->value;
}

int main()
{
    printf("top = 0x%x\n", top);
    printf("isEmpty? = %d\n", isEmpty());
    push(5);
    push(32);
    push(-100);
    push(-50);
    printStack();
    printf("Peek : %3d\n", peek());
    pop();
    printf("Peek : %3d\n", peek());
    pop();
    printf("Peek : %3d\n", peek());
    pop();
    printf("Peek : %3d\n", peek());
    pop();
    printf("Peek : %3d\n", peek());
    pop();
    printf("Peek : %3d\n", peek());
    pop();
}

static STACK_PTR_t createNode()
{
    return (STACK_PTR_t)malloc(sizeof(STACK_NODE_t));
}

static void printStack()
{
    STACK_PTR_t temp = top;
    while(temp != NULL)
    {
        printf("%3d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}