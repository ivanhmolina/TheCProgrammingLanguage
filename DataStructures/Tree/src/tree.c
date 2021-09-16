#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static TREE_NODE_PTR_t createTreeNode(int32_t value);

TREE_NODE_PTR_t insertTreeNode(TREE_NODE_PTR_t head, int32_t value)
{
    TREE_NODE_PTR_t temp;
    if(head == NULL)
        return createTreeNode(value);
    if(value > head->value)
    {
        temp = insertTreeNode(head->right, value);
        head->right = temp;
    }
    if(value <= head->value)
    {
        temp = insertTreeNode(head->left, value);
        head->left = temp;
    }
    return head;
}

void printTree(TREE_NODE_PTR_t head)
{
    if(head == NULL)
        printf("Tree is empty\n");
    
    if(head->left != NULL)
        printTree(head->left);
    
    printf("%d, ", head->value);
    
    if(head->right != NULL)
        printTree(head->right);
}

TREE_NODE_PTR_t searchTreeNode(TREE_NODE_PTR_t head, int32_t value)
{
    if(head == NULL)
        return NULL;
    if(value == head->value)
        return head;
    if(value > head->value) //Look right
        return searchTreeNode(head->right, value);
    if(value < head->value) //Look left
        return searchTreeNode(head->left, value);
}

/*void deleteTreeNode(TREE_NODE_PTR_t head, int32_t value)
{
    if(head == NULL)
        printf("Tree is already empty\n");
    if(head->value == value)
    {

    }
}*/

int main()
{
    TREE_NODE_PTR_t tree = NULL;
    TREE_NODE_PTR_t temp_node;
    tree = insertTreeNode(tree, 5);
    printf("head = %d\n", tree->value);
    
    printf("insertTreeNode\n");
    tree = insertTreeNode(tree, 3);
    tree = insertTreeNode(tree, 4);
    tree = insertTreeNode(tree, 6);
    printf("left = %d\n", tree->left->value);
    printf("right = %d\n", tree->right->value);
    
    printf("printTree\n");
    printTree(tree);

    printf("searchTreeNode\n");
    for (size_t i = 0; i < 7; i++)
    {
        temp_node = searchTreeNode(tree, i);
        if (temp_node == NULL)
            printf("search(%d)= NULL\n", i);
        else
            printf("search(%d)= %d\n", i, temp_node->value);
    }
    
}

static TREE_NODE_PTR_t createTreeNode(int32_t value)
{
    TREE_NODE_PTR_t temp = (TREE_NODE_PTR_t)malloc(sizeof(TREE_NODE_t));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
