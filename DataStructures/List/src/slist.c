#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static SLIST_NODE_t *createListNode(uint32_t value);
static void peekList();
static SLIST_NODE_t *searchTailListNode(SLIST_NODE_t *head);
static SLIST_NODE_t *findPosListNode(SLIST_NODE_t *head, uint8_t position);

void printList(SLIST_NODE_t *head)
{
    printf("[");
    for(;head->next != NULL; head = head->next)
    {
        printf("%d, ", head->value);
    }
    printf("%d]\n", head->value);
}

void pushListNode(SLIST_NODE_t **head, int32_t value)
{
    if(head[0] == NULL)
    {
        //Create a new node and assign as head
        head[0] = createListNode(value);
    }
    else
    {
        //Create a new node and replace head
        SLIST_NODE_t *temp = createListNode(value);
        temp->next = head[0];
        head[0] = temp;
    }
}

void appendListNode(SLIST_NODE_t **head, int32_t value)
{
    if(head[0] == NULL)
    {
        //Create a new node and assign as head
        head[0] = createListNode(value);
    }
    else
    {
        //Create a new node, search for tail & append
        SLIST_NODE_t *tail = searchTailListNode(head[0]);
        tail->next = createListNode(value);
    }
}

void insertListNode(SLIST_NODE_t **head, int8_t position, int32_t value)
{
    if(head[0] == NULL)
    {
        //Create a new node and assign as head
        if(position == 0)
            head[0] = createListNode(value);
        else
            printf("Position %u doesn't exist\n", position);
    }
    else if(position == 0)
    {
        SLIST_NODE_t *newNode = createListNode(value);
        newNode->next = head[0];
        head[0] = newNode;
    }
    else
    {
        //Create New Node, Find position, Insert
        SLIST_NODE_t *newNode = createListNode(value);
        SLIST_NODE_t *posNode = findPosListNode(head[0], position-1);
        if(posNode == NULL)
        {
            printf("Position %u doesn't exist\n", position);
            free(newNode);
        }
        else
        {
            newNode->next = posNode->next;
            posNode->next = newNode;
        }
    }
}

int main()
{
    SLIST_NODE_t *head = NULL;
    pushListNode(&head, 5);
    peekList(head);
    for (size_t i = 0; i < 5; i++)
        appendListNode(&head, i);
    for (size_t i = 0; i < 5; i++)
        pushListNode(&head, i);
    printList(head);
    peekList(head);
    insertListNode(&head, 6, 9);
    insertListNode(&head, 13, 9);
    insertListNode(&head, 12, 9);
    insertListNode(&head, 0, 9);
    insertListNode(&head, -1, 9);
    printList(head);
}

static SLIST_NODE_t *createListNode(uint32_t value)
{
    SLIST_NODE_t *new = (SLIST_NODE_t *)malloc(sizeof(SLIST_NODE_t));
    new->value = value;
    new->next = NULL;
    return new;
}

static void peekList(SLIST_NODE_t *head)
{
    if(head == NULL)
        printf("Head is empty\n");
    else
        printf("Head value = %d\n", head->value);
}

static SLIST_NODE_t *searchTailListNode(SLIST_NODE_t *head)
{
    for(;head->next != NULL; head = head->next);
    return head;
}

static SLIST_NODE_t *findPosListNode(SLIST_NODE_t *head, uint8_t position)
{
    for (size_t i = 0; i < position && head != NULL; i++, head = head->next);
    return head;
}