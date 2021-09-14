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

void push(ELEMENT_t value, TYPES_T vtype)
{
    if(isEmpty(top))
    {
        top = createNode();
        top->value = value;
        top->utype = vtype;
        top->next = NULL;
    }
    else
    {
        STACK_PTR_t temp = createNode();
        temp->value = value;
        temp->utype = vtype;
        temp->next = top;
        top = temp;
    }
}

ELEMENT_t pop()
{
    STACK_PTR_t temp = top;
    ELEMENT_t val = top->value;

    if(isEmpty(top))
    {
        return (ELEMENT_t)NULL;
    }
    else
    {
        top = top->next;
        free(temp);
    }

    return val;
}

ELEMENT_t peek()
{
    if(isEmpty(top))
        return (ELEMENT_t)NULL;
    else
        return top->value;
}

int main()
{
    printf("top = 0x%x\n", top);
    printf("isEmpty? = %d\n", isEmpty());
    push((ELEMENT_t)5, INT32);
    push((ELEMENT_t)32, INT32);
    push((ELEMENT_t)-100, INT32);
    push((ELEMENT_t)-50, INT32);
    push((ELEMENT_t)5, INT32);
    push((ELEMENT_t)16, INT32);
    push((ELEMENT_t)(void *)"hola", STRING);
    push((ELEMENT_t)32, INT32);
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
    printf("top = 0x%x\n", *top);
    
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
        switch (temp->utype)
        {
        case INT32:
            printf("%3d ", temp->value);
            break;
        case STRING:
            printf("%s ", temp->value);
            break;
        default:
            printf("Unrecognized element of size: %d\n", sizeof(temp->value));
        }
        
        temp = temp->next;
    }
    printf("\n");
}