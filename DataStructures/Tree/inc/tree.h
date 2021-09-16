#ifndef _TREE_
#define _TREE_

#include "ptypes.h"

typedef struct TREE_NODE_s *TREE_NODE_PTR_t;

typedef struct TREE_NODE_s
{
    int32_t value;
    TREE_NODE_PTR_t left;
    TREE_NODE_PTR_t right;
}TREE_NODE_t;

//INSERT
/**  
 * Inserts node with value specified in tree and returns pointer to head
 * @param   head    pointer to head node of the tree.
 * @param   value   the value to insert in the tree. 
 * @result  A pointer to tree head, returns NULL when failing.
*/
TREE_NODE_PTR_t insertTreeNode(TREE_NODE_PTR_t head, int32_t value);

//SEARCH
/**  
 * Search node with value specified in tree and returns its pointer
 * @param   head    pointer to head node of the tree.
 * @param   value   the value to search in the tree. 
 * @result  A pointer to the found node, returns NULL when not in tree.
*/
TREE_NODE_PTR_t searchTreeNode(TREE_NODE_PTR_t head, int32_t value);

void deleteTreeNode(TREE_NODE_PTR_t head, int32_t value);

//TRAVERSAL
/**  
 * Prints tree from left to right
 * @param   head    pointer to head node of the tree.
 * @result  Prints the value of each tree node.
*/
void printTree(TREE_NODE_PTR_t head);

#endif