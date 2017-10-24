#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "BST.h"

struct Node {
    TYPE value;
    struct Node * left;
    struct Node * right;
};

struct BinarySearchTree {
    struct Node *root;
    int size;
};

void initBST(struct BinarySearchTree *tree) {
    tree->size = 0;
    tree->root = 0;
}

void addBST(struct BinarySearchTree *tree, TYPE newValue) {
    tree->root = _nodeAddBST(tree->root, newValue);
    tree->size++;
}

int sizeBST(struct BinarySearchTree *tree) {
    return tree->size;
}

struct Node *_nodeAddBST(struct Node *current, TYPE newValue) {
    struct Node *newnode;
    if (current == NULL) {
        newnode = malloc(sizeof(struct Node));
        assert(newnode != 0);
        newnode->value = newValue;
        newnode->left = 0;
        newnode->right = 0;
        return newnode;
    }
    if (newValue < current->value) {
        current->left = _nodeAddBST(current->left, newValue);
    } else {
        current->right = _nodeAddBST(current->right, newValue);
    }
}

int containsBST(struct BinarySearchTree *tree, TYPE d) {
    struct Node *testNode;
    testNode = tree->root;
    while (testNode != NULL){
        if (testNode->value == d) {
            return 1;
        } else if (testNode->value < d) {
            testNode = testNode->right;
        } else {
            testNode = testNode->left;
        }
    }
    return 0;
}

void removeBST(struct BinarySearchTree *tree, TYPE d) {
    if (containsBST(tree, d)){
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
}

TYPE _leftMostChild(struct Node *current) {
    while(current->left != NULL) {
        current = current->left;
    }
    return current->value;
}

struct Node *_removeLeftmostChild(struct Node *current) {
    assert(current != NULL);
    struct Node *tempLink = current->right;
    if (current->left == NULL) {
        free(current);
        return tempLink;
    }
    else {
        current->left = _removeLeftmostChild(current->left);
    }
    return current;
}

struct Node *_nodeRemoveBST(struct Node *current, TYPE d) {
    assert(current != NULL);
    if (current->value == d) {
        if(current->right == NULL) {
            struct Node *tempNode = current->right;
            free(current);
            return tempNode;
        }
        current->value = _leftMostChild(current->right);
        current->right = _removeLeftmostChild(current->right);
    }
    else if (current->value > d) {
        current->left = _nodeRemoveBST(current->left, d);
    }
    else {
        current->right = _nodeRemoveBST(current->right, d);
    }
    return current;
}