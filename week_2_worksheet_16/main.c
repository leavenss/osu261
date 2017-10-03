/*This code implements a Dynamic Array Stack*/

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "dynamicArrayStack.h"

/* ******************************* *
 * Regular dynamic array functions *
 * ******************************* */

void initDynArr(struct DynArr *v, int capacity)
{
    v->data = malloc(sizeof(TYPE) * capacity);
    assert(v->data != 0);
    v->size = 0;
    v->capacity = capacity;
}

void freeDynArr(struct DynArr *v)
{
    if(v->data != 0)
    {
        free(v->data); /* free the space on the heap */
        v->data = 0; /* make it point to null */
    }
    v->size = 0;
    v->capacity = 0;
}

int sizeDynArr( struct DynArr *v){
    return v->size;
}

void addDynArr(struct DynArr *v, TYPE val)
{
    /* Check to see if a resize is necessary */
    if(v->size >= v->capacity)
        _setCapacityDynArr(v, 2 * v->capacity);
    v->data[v->size] = val;
    v->size++;
}

void _setCapacityDynArr(struct DynArr *v, int newCap)
{
    /* Create new DynArr struct to hold larger array */
    struct DynArr myNewData;
    /* Initialize new DynArr struct with newCap capacity */
    initDynArr(&myNewData, newCap);
    /* Copy values of old array into newly created array */
    for (int a = 0; a < v->size; a++) {
        addDynArr(&myNewData, v->data[a]);
    }
    /* Free memory used by old array */
    freeDynArr(v);
    /* Have v point to the newly created array */
    *v = myNewData;
}

/* *************************************************** *
 * Dynamic Array implementation of the Stack Interface *
 * *************************************************** */
void pushDynArray (struct DynArr * da, TYPE e) {
    assert(da!=0);
    addDynArr(da, e);
}

TYPE topDynArray (struct DynArr * da) {
    assert(da!=0);
    assert(!isEmptyDynArray(da));
    return da->data[da->size-1];
}

void popDynArray (struct DynArr * da) {
    assert(da!=0);
    assert(!isEmptyDynArray(da));
    da->size--;
}

int isEmptyDynArray (struct DynArr * da) {
    if(da->size == 0)
        return 1;
    else
        return 0;
}

int main() {

    struct DynArr *myDynArr;
    initDynArr(myDynArr, 5);
    printf("Initial size (not capacity) is %d\n", sizeDynArr(myDynArr));
    pushDynArray(myDynArr, 5);
    pushDynArray(myDynArr, 8);
    pushDynArray(myDynArr, 12);
    printf("Size is now %d\n", sizeDynArr(myDynArr));
    printf("The top of the stack is %d\n", topDynArray(myDynArr));
    popDynArray(myDynArr);
    printf("After popping, the top of the stack is %d\n", topDynArray(myDynArr));

    return 0;
}