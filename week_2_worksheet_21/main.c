#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "dynamicArrayBag.h"

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

/* This is used by the removeDynArr function below */
void _dynArrayRemoveAt (struct DynArr * da, int index) {
    assert((index >= 0) && (index < (da->size)));
    while (index < da->size) {
        da->data[index] = da->data[index + 1]; //shifting everything over
        index++;
    }
    da->size--; //decrease size of array by 1
}

void removeDynArr (struct DynArr * da, TYPE test) {
    int i;
    for (i = 0; i < da->size; i++) {
        if (EQ(test, da->data[i])) { /* found it */
            _dynArrayRemoveAt(da, i);
            return;
        }
    }
}

int containsDynArr (struct DynArr * da, TYPE e) {
    int i;
    for (i = 0; i < da->size;i++) {
        if (da->data[i] == e) {
            return 1;
        }
    }
    return 0;
}


int main() {

    struct DynArr *myDynArr;
    initDynArr(myDynArr, 5);
    printf("Initial size (not capacity) is %d\n", sizeDynArr(myDynArr));
    addDynArr(myDynArr, 5);
    addDynArr(myDynArr, 8);
    addDynArr(myDynArr, 12);
    printf("Size is now %d\n", sizeDynArr(myDynArr));

    printf("Check to see if bag contains 8: ");
    if (containsDynArr(myDynArr, 8)){
        printf("True\n");
    } else {
        printf("False\n");
    }

    removeDynArr(myDynArr, 8);
    printf("Size after removing 8: %d\n", sizeDynArr(myDynArr));

    printf("Check to see if bag contains 8: ");
    if (containsDynArr(myDynArr, 8)){
        printf("True\n");
    } else {
        printf("False\n");
    }


    freeDynArr(myDynArr);

    return 0;
}