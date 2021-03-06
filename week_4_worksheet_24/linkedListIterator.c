/* CS261- Assignment 3 - Problem 1
 * Name: Taylor Liss
 * Date: 10/13/17
 * Solution description: This file implements a deque and bag with a doubly­linked list with sentinels
 */

#include "linkedListIterator.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
    TYPE value;
    struct Link* next;
    struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
    int size;
    struct Link* frontSentinel;
    struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
    list->frontSentinel = malloc(sizeof(struct Link));
    assert(list->frontSentinel != 0);
    list->backSentinel = malloc(sizeof(struct Link));
    assert(list->backSentinel != 0);

    list->frontSentinel->next = list->backSentinel;
    list->frontSentinel->prev = 0;

    list->backSentinel->prev = list->frontSentinel;
    list->backSentinel->next = 0;
    list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
    struct Link* newLink = malloc(sizeof(struct Link));
    assert(newLink != 0);
    newLink->value = value;

    newLink->next = link;
    newLink->prev = link->prev;
    link->prev = newLink;
    newLink->prev->next = newLink;

    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
    assert(!linkedListIsEmpty(list));
    link->prev->next = link->next;
    link->next->prev = link->prev;
    free(link);
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
    struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
    init(newDeque);
    return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
    while (!linkedListIsEmpty(list))
    {
        linkedListRemoveFront(list);
    }
    free(list->frontSentinel);
    free(list->backSentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
    addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
    return(list->frontSentinel->next->value);
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
    return(list->backSentinel->prev->value);
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
    removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
    removeLink(list, list->backSentinel->prev);

}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
    if (list->frontSentinel->next == list->backSentinel && list->backSentinel->prev == list->frontSentinel){
        return 1;
    } else {
        return 0;
    }
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
    int i;
    struct Link* iterator;

    iterator = list->frontSentinel->next;
    for (i=0; i < list->size; i++){
        printf("%d ",iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
    linkedListAddFront(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
    assert(!linkedListIsEmpty(list));
    int isInBag = 0;
    int i;
    struct Link* iterator;

    iterator = list->frontSentinel->next;
    for (i=0; i < list->size; i++){
        if (iterator->value == value){
            isInBag = 1;
        }
        iterator = iterator->next;
    }
    return isInBag;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
    assert(!linkedListIsEmpty(list));
    assert(linkedListContains(list, value));
    int i;
    struct Link* iterator;

    iterator = list->frontSentinel->next;
    for (i=0; i < list->size; i++){
        if (iterator->value == value){
            removeLink(list,iterator);
            break;
        }
        iterator = iterator->next;
    }
}

/*****************New Stuff*********************/

/** Iterator interface **/
struct linkedListIterator {
    struct LinkedList * lst;
    struct Link * currentLink;
};

/** Initialize an iterator **/
void linkedListIteratorInit (struct LinkedList  *lst, struct linkedListIterator * itr) {
    itr->lst = lst;
    itr->currentLink = lst->frontSentinel->next;
}

void _removeLink (struct LinkedList  *lst, struct Link *lnk){
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;

    free(lnk);

    lst->size--;
}

/* Determines if there are more values in the collection and if so, returns true. It also sets up for the subsequent
 * call to linkedListIteratorNext() by making currentLink point to the next value in the collection. */
int linkedListIteratorHasNext (struct linkedListIterator *itr) {
    if (itr->currentLink->next != itr->lst->backSentinel){
        itr->currentLink = itr->currentLink->next;
        return(1);
    } else {
        return(0);
    }
}

/* Returns the next value in the collection */
TYPE linkedListIteratorNext (struct linkedListIterator *itr) {
    return (itr->currentLink->value);
}

/* removes the last value returned by linkedListIteratorNext() Notice that we use a tmp to ensure that the following
 * calls to linkedListIteratorHasNext() and linkedListIteratorNext() are correct after removal of the current link */
void linkedListIteratorRemove (struct linkedListIterator *itr) {
    struct Link *tmp = itr->currentLink;
    itr->currentLink = itr->currentLink->prev;
    _removeLink(itr->lst, tmp);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}