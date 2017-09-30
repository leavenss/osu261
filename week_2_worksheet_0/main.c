#include <stdio.h>
#include <stdlib.h>
#include "arrayBagStack.h"

struct arrayBagStack {
    TYPE data [100];
    int count;
};

struct arrayBagStack * createArray()
{
    struct arrayBagStack * b = malloc(sizeof(struct arrayBagStack));

    return b;
}

void initArray (struct arrayBagStack * b){
    b->count=0;
}

void addArray(struct arrayBagStack * b, TYPE v){};
int containsArray(struct arrayBagStack * b, TYPE v){};
void removeArray(struct arrayBagStack * b, TYPE v){};
int sizeArray(struct arrayBagStack * b){};

void pushArray (struct arrayBagStack * b, TYPE v){};
TYPE topArray (struct arrayBagStack * b){};
void popArray (struct arrayBagStack * b){};
int isEmptyArray (struct arrayBagStack * b){};


int main() {
    printf("Hello, World!\n");

    struct arrayBagStack b;
    initArray(&b);

    return 0;
}