#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static TREE_NODE_PTR_t createTreeNode(int32_t value);
static TREE_NODE_PTR_t insertNodeInTree(TREE_NODE_PTR_t head, TREE_NODE_PTR_t new);
static TREE_NODE_PTR_t insertLeftToRightTree(TREE_NODE_PTR_t tree1, TREE_NODE_PTR_t tree2);
static TREE_NODE_PTR_t insertRightToLeftTree(TREE_NODE_PTR_t tree1, TREE_NODE_PTR_t tree2);

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

TREE_NODE_PTR_t deleteTreeNode(TREE_NODE_PTR_t head, int32_t value)
{
    TREE_NODE_PTR_t new_head;
    if(head == NULL)
        return NULL;

    if (head->left != NULL && head->value > value)
    {
        new_head = head;
        new_head->left = deleteTreeNode(head->left, value);
        return new_head;
    }

    if (head->value == value)
    {
        if (head->right != NULL)
        {
            //Assign right as new head
            new_head = head->right;
            //Insert left tree into right tree
            insertLeftToRightTree(head->left, head->right);
            free(head);
            return new_head;
        }
        else if(head->left != NULL)
        {
            //Assign left as new head
            new_head = head->left;
            //Insert right tree into left tree
            insertRightToLeftTree(head->right, head->left);
            free(head);
            return new_head;
        }
        else
        {
            free(head);
            return NULL;
        }
    }

    if (head->right != NULL && head->value < value)
    {
        new_head = head;
        new_head->right = deleteTreeNode(head->right, value);
        return new_head;
    }
        
}

#ifdef DEBUG_BTREE
int main()
{
    TREE_NODE_PTR_t tree = NULL;
    TREE_NODE_PTR_t temp_node;
    tree = insertTreeNode(tree, 5);
    printf("head = %d\n", tree->value);
    
    printf("insertTreeNode\n");
    tree = insertTreeNode(tree, 3);
    tree = insertTreeNode(tree, 4);
    tree = insertTreeNode(tree, 8);
    tree = insertTreeNode(tree, 2);
    tree = insertTreeNode(tree, 6);
    tree = insertTreeNode(tree, 9);
    printf("left = %d\n", tree->left->value);
    printf("right = %d\n", tree->right->value);
    
    printf("printTree\n");
    printTree(tree);
    printf("\n");

    printf("searchTreeNode\n");
    for (size_t i = 0; i < 7; i++)
    {
        temp_node = searchTreeNode(tree, i);
        if (temp_node == NULL)
            printf("search(%d)= NULL\n", i);
        else
            printf("search(%d)= %d\n", i, temp_node->value);
    }

    printf("head = %d\n", tree->value);
    printf("left = %d\n", tree->left->value);
    printf("right = %d\n", tree->right->value);

    printf("deleteTreeNode\n");
    tree = deleteTreeNode(tree, 6);
    printTree(tree);
    printf("\n");
    printf("head = %d\n", tree->value);
}
#endif

static TREE_NODE_PTR_t createTreeNode(int32_t value)
{
    TREE_NODE_PTR_t temp = (TREE_NODE_PTR_t)malloc(sizeof(TREE_NODE_t));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

static TREE_NODE_PTR_t insertNodeInTree(TREE_NODE_PTR_t head, TREE_NODE_PTR_t new)
{
    TREE_NODE_PTR_t temp;
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

//BALANCE TREE
/**  
 * Insert tree 1 into tree 2 tail
 * @param   left    pointer to left tree that is going to be filled
 * @param   right   pointer to the right tree that is going to be traversed
 * @result  Returns pointer to the head of the inserted left tree
*/
static TREE_NODE_PTR_t insertLeftToRightTree(TREE_NODE_PTR_t tree1, TREE_NODE_PTR_t tree2)
{
    if (tree2 == NULL)
        return NULL;
    
    if (tree1 == NULL)
        return tree2;

    if (tree2->left != NULL)
        return insertLeftToRightTree(tree1, tree2->left);

    return insertNodeInTree(tree2, tree1);
}


static TREE_NODE_PTR_t insertRightToLeftTree(TREE_NODE_PTR_t tree1, TREE_NODE_PTR_t tree2)
{
    if (tree2 == NULL)
        return NULL;

    if (tree1 == NULL)
        return tree2;

    if (tree2->right != NULL)
        return insertRightToLeftTree(tree1, tree2->right);

    return insertNodeInTree(tree2, tree1);
}
