#include "BST.h"
#include <stdio.h>

int main() {

    char testContains(struct BinarySearchTree *tree, int testNum){
        printf("Does tree contain %d?: ", testNum);
        if (containsBST(tree, testNum) == 1){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    struct BinarySearchTree* myBst;

    initBST(myBst);

    printf("Adding 5, 8, and 3\n");
    addBST(myBst, 5);
    addBST(myBst, 8);
    addBST(myBst, 3);

    printf("Size of myBst is %d\n", sizeBST(myBst));

    testContains(myBst, 8);
    testContains(myBst, 9);
    testContains(myBst, 3);

    printf("Removing 3\n");
    removeBST(myBst, 3);

    testContains(myBst, 8);
    testContains(myBst, 9);
    testContains(myBst, 3);

    printf("Size of myBst is %d\n", sizeBST(myBst));

    return 0;
}