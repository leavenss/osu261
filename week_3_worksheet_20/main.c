/* This program contains the implementation of a dynamic array deque and queue */

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "queuedeque.h"

void _dequeSetCapacity (struct deque *d, int newCap) {
    int i;
    /* Create a new underlying array*/
    TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
    assert(newData != 0);
    /* copy elements to it */
    int j = d->beg;
    for(i = 0; i < d->size; i++)
    {
        newData[i] = d->data[j];
        j = j + 1;
        if(j >= d->capacity)
            j = 0;
    }
    /* Delete the old underlying array*/
    free(d->data);
    /* update capacity and size and data*/
    d->data = newData;
    d->capacity = newCap;
    d->beg = 0;
}

void dequeFree (struct deque *d) {
    free(d->data); d->size = 0; d->capacity = 0;
}

void dequeInit (struct deque *d, int initCapacity) {
    d->size = 0;
    d->beg = 0;

    d->capacity = initCapacity;
    assert(initCapacity > 0);
    d->data = (TYPE *) malloc(initCapacity * sizeof(TYPE));
    assert(d->data != 0);
}

int dequeSize (struct deque *d) {
    return d->size;
}

void dequeAddFront (struct deque *d, TYPE newValue) {
    if (d->size >= d->capacity) {
        _dequeSetCapacity(d, 2 * d->capacity);
    }
    //TODO: Implement this
    int index;
    index = d->beg = d->size-1;
    if (index > d->capacity){
        index -= d->capacity;
    }
    d->data[d->beg-1] = newValue;
    d->size++;
}

void dequeAddBack (struct deque *d, TYPE newValue) {
    int index;
    if (d->size >= d->capacity) {
        _dequeSetCapacity(d, 2* d->capacity);
    }
    index = d->beg + d->size;
    if (index >= d->capacity){
        index -= d->capacity;
    }
    d->data[index] = newValue;
    d->size++;
}

TYPE dequeFront (struct deque *d) {
    //TODO: Implement this
    return d->data[d->beg];
}

TYPE dequeBack (struct deque *d) {
    int index;
    index = d->beg + d->size - 1;
    if (index > d->capacity){
        index -= d->capacity;
    }
    return d->data[index];
}

void dequeRemoveFront (struct deque *d) {
    //TODO: Implement this
    assert(d->size > 0);
    d->size--;
    if (d->beg == d->capacity-1){
        d->beg = 0;
    } else {
        d->beg++;
    }
}

void dequeRemoveBack (struct deque *d) {
    assert(d->size > 0);
    d->size--;
}

int main() {

    struct deque myDeque;
    dequeInit(&myDeque, 5);


    return 0;
}