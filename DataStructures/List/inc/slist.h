#ifndef _SLIST_
#define _SLIST_

#include "ptypes.h"

typedef struct SLIST_NODE_s
{
    int32_t value;
    struct SLIST_NODE_s *next;
}SLIST_NODE_t;

//TRAVERSAL
void printList();

//INSERTION
void pushListNode(SLIST_NODE_t **head, int32_t value);

void appendListNode(SLIST_NODE_t **head, int32_t value);

void insertListNode(SLIST_NODE_t **head, int8_t position, int32_t value);

//DELETION 
void deleteListNode(SLIST_NODE_t **head, int8_t position);

void popListNode(SLIST_NODE_t **head);

//SEARCHING
/**  
 * Returns position when matched value is found in list
 * @param   head    pointer to head node of the list.
 * @param   value   the value to search in the list. 
 * @result  The position of the first node that contains the value.
 *          Returns -1 when not found.
*/
int16_t searchListNode(SLIST_NODE_t *head, int32_t value);

//UPDATING
void updateListNode(SLIST_NODE_t *head, int8_t position, int32_t value);

//SORTING
void sortListNode(SLIST_NODE_t *head);

//MERGING
void mergeLists(SLIST_NODE_t *list1, SLIST_NODE_t *list2);

#endif