#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static SLIST_NODE_t *createListNode(uint32_t value);
static void peekList();
static SLIST_NODE_t *searchTailListNode(SLIST_NODE_t *head);
static SLIST_NODE_t *findPosListNode(SLIST_NODE_t *head, uint8_t position);
static TREE_LIST_NODE_PTR_t createTreeNode(int32_t value);
static TREE_LIST_NODE_PTR_t insertNodeInTree(TREE_LIST_NODE_PTR_t head, TREE_LIST_NODE_PTR_t new);
static TREE_LIST_NODE_PTR_t createTreefromList(SLIST_NODE_PTR_t list_head);
static void treeSort(SLIST_NODE_PTR_t *list, TREE_LIST_NODE_PTR_t tree);

void sortListNode(SLIST_NODE_t *head)
{
    SLIST_NODE_PTR_t temp = head;
    TREE_LIST_NODE_PTR_t tree = createTreefromList(head);

    treeSort(&temp, tree);
}



void printList(SLIST_NODE_t *head)
{
    if(head == NULL)
    {
        printf("[empty]\n");
    }
    else
    {
        printf("[");
        for (; head->next != NULL; head = head->next)
        {
            printf("%d, ", head->value);
        }
        printf("%d]\n", head->value);
    }
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

void deleteListNode(SLIST_NODE_t **head, int8_t position)
{
    if(position == 0)
    {
        popListNode(head);
    }
    else
    {
        SLIST_NODE_t *temp = findPosListNode(head[0], position-1);
        if(temp == NULL || temp->next == NULL)
        {
            printf("Position %u doesn't exist\n", position);
        }
        else
        {
            SLIST_NODE_t *deln = temp->next;
            temp->next = temp->next->next;
            free(deln);
        }
    }
}

void popListNode(SLIST_NODE_t **head)
{
    if(head[0] ==  NULL)
    {
        //Head is already empty
        printf("Head already empty\n");
    }
    else
    {
        SLIST_NODE_t *temp = head[0];
        head[0] = head[0]->next;
        free(temp);
    }
}

int16_t searchListNode(SLIST_NODE_t *head, int32_t value)
{
    if(head == NULL)
        return -1;
    for(int16_t position = 0; head != NULL; head = head->next, position++)
        if (head->value == value)
            return position;
    return -1;
}

void updateListNode(SLIST_NODE_t *head, int8_t position, int32_t value)
{
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        SLIST_NODE_t *temp = findPosListNode(head, position);
        if(temp == NULL)
            printf("Position %d doesn't exist\n", position);
        else
            temp->value = value;
    }
}

SLIST_NODE_t *mergeLists(SLIST_NODE_t *list1, SLIST_NODE_t *list2)
{
    if(list1 == NULL)
        list1 = list2;
    else
    {
        SLIST_NODE_t *tail = searchTailListNode(list1);
        tail->next = list2;
    }
    return list1;
}

void listToArray(SLIST_NODE_t* head, SLIST_NODE_t **array, uint8_t len)
{
    for (uint8_t pos = 0; head != NULL && pos < len; head = head->next, pos++)
        array[pos] = head;
}

int main()
{
    SLIST_NODE_t *head = NULL;
    SLIST_NODE_t *head2 = NULL;
    SLIST_NODE_PTR_t list = NULL;
    SLIST_NODE_t *array[LIST_MAX_ELEMENTS];

    printf("printList peekList\n");
    printList(head);
    pushListNode(&head, 5);
    printList(head);
    peekList(head);
    
    printf("appendListNode\n");
    for (size_t i = 0; i < 5; i++)
        appendListNode(&head, i);
    printList(head);
    
    printf("pushListNode\n");
    for (size_t i = 0; i < 5; i++)
        pushListNode(&head, i);
    printList(head);

    printf("insertListNode\n");
    insertListNode(&head, 6, 9);
    insertListNode(&head, 13, 9);
    insertListNode(&head, 12, 9);
    insertListNode(&head, 0, 9);
    insertListNode(&head, -1, 9);
    printList(head);

    printf("popListNode\n");
    for (size_t i = 0; i < 5; i++)
    {
        popListNode(&head);
    }
    printList(head);

    printf("deleteListNode\n");
    for (size_t i = 0; i < 5; i++)
    {
        deleteListNode(&head, i);
    }
    printList(head);

    printf("searchListNode\n");
    for (size_t i = 0; i < 7; i++)
    {
        printf("searchListNode(%d): pos=%d\n", i, searchListNode(head, i));
    }
    printList(head);

    printf("updateListNode\n");
    for (size_t i = 0; i < 5; i++)
    {
        updateListNode(head, i, i);
    }
    printList(head);

    printf("Initialize list2\n");
    for (size_t i = 0; i < 4; i++)
    {
        pushListNode(&head2, i);
    }
    printList(head2);

    printf("mergeLists\n");
    head = mergeLists(head, head2);
    printList(head);

    printf("Experiment\n");
    for (size_t i = 0; i < 7; i++)
        printf("Experiment(%d): %d\n", i, head[i].value);

    printf("listToArray\n");
    listToArray(head, array, LIST_MAX_ELEMENTS);
    for (size_t i = 0; i < 8; i++)
        printf("Array[%d]=%d\n", i, array[i]->value);

    printf("Initialize list3\n");
    for (size_t i = 0; i < 7; i++)
    {
        pushListNode(&list, i);
    }
    printList(list);

    printf("sortListNode\n");
    sortListNode(list);
    printList(list);
    sortListNode(head);
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
    if(head->next != NULL)
        return searchTailListNode(head->next);
    return head;
    
    /*for(;head->next != NULL; head = head->next);
    return head;*/
}

static SLIST_NODE_t *findPosListNode(SLIST_NODE_t *head, uint8_t position)
{
    for (size_t i = 0; i < position && head != NULL; i++, head = head->next);
    return head;
}

static TREE_LIST_NODE_PTR_t createTreeNode(int32_t value)
{
    TREE_LIST_NODE_PTR_t temp = (TREE_LIST_NODE_PTR_t)malloc(sizeof(TREE_LIST_NODE_t));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

static TREE_LIST_NODE_PTR_t insertNodeInTree(TREE_LIST_NODE_PTR_t head, TREE_LIST_NODE_PTR_t new)
{
    TREE_LIST_NODE_PTR_t temp;
    if (head == NULL)
        return new;
    if (new->value > head->value)
    {
        temp = insertNodeInTree(head->right, new);
        head->right = temp;
    }
    if (new->value <= head->value)
    {
        temp = insertNodeInTree(head->left, new);
        head->left = temp;
    }
    return head;
}

static TREE_LIST_NODE_PTR_t createTreefromList(SLIST_NODE_PTR_t list_head)
{
    TREE_LIST_NODE_PTR_t tree = NULL;

    if (list_head == NULL)
        return NULL;

    for (; list_head != NULL; list_head = list_head->next)
    {
        tree = insertNodeInTree(tree, createTreeNode(list_head->value));
    }

    return tree;
}

static void treeSort(SLIST_NODE_PTR_t *list, TREE_LIST_NODE_PTR_t tree)
{
    uint32_t temp;
    if (list == NULL || tree == NULL)
        printf("Invalid parameters\n");

    if (tree->left != NULL)
        treeSort(list, tree->left);

    list[0]->value = tree->value;
    list[0] = list[0]->next;

    if (tree->right != NULL)
        treeSort(list, tree->right);
}