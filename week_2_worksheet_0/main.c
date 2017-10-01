#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrayBagStack.h"


//This returns a pointer to an arrayBagStack struct
struct arrayBagStack * createArray()
{
    struct arrayBagStack * b = malloc(sizeof(struct arrayBagStack));

    return b;
}

void initArray (struct arrayBagStack * b){
    b->count=0;
}

void addArray(struct arrayBagStack * b, TYPE v){
    b->data[b->count]=v;
    b->count++;
};

int containsArray(struct arrayBagStack * b, TYPE v){
    int i;
    for(i=0; i<b->count; i++){
        if(EQ(b->data[i],v)) {
            return 1;
        }
    return 0;
    }
};

void removeArray(struct arrayBagStack * b, TYPE v) {
    int i = 0;
    int j;
    assert(containsArray(b, v));

    while (!EQ(b->data[i], v)) {
        i = i + 1;
    }
    for (j = i; j < b->count-1; j++){
        b->data[j] = b->data[j + 1];
    }
    b->count=b->count-1;
};

int sizeArray(struct arrayBagStack * b){
    return b->count;
};

/*Stack Interfaces*/
void pushArray (struct arrayBagStack * b, TYPE v){
    addArray(b,v);
};
TYPE topArray (struct arrayBagStack * b){
    assert(!isEmptyArray(b));
    return b->data[b->count-1];
};

void popArray (struct arrayBagStack * b){
    assert(!isEmptyArray(b));
    b->count--;
};

int isEmptyArray (struct arrayBagStack * b){
    return(!b->count);
};

void printArray(struct arrayBagStack *b){
    int i;
    for(i=0; i<100; i++){
        printf("Array[i]=%d\n",b->data[i]);
    }
}

int main() {
    printf("Hello, World!\n");

    //d is a pointer to an arrayBagStack struct
    struct arrayBagStack *myBag;
    myBag = createArray();

    initArray(myBag);
    addArray(myBag, 7);

    int myNum = 8;
    printf("Does myBag contain %d?\n", myNum);
    if(containsArray(myBag, myNum) == 1){
        printf("Yes");
    } else {
        printf("No");
    }

    //printArray(myBag);


    return 0;
}