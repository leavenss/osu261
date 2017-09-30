#include <stdio.h>
#include <arrayBagStack.h>

void initArray (struct arrayBagStack * b){

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