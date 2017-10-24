//
// Created by tliss on 10/24/2017.
//

#ifndef WEEK_5_WORKSHEET_29_BST_H
#define WEEK_5_WORKSHEET_29_BST_H

#ifndef TYPE
#define TYPE int
#endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

struct Node;

struct BinarySearchTree;

void initBST(struct BinarySearchTree *tree);

void addBST(struct BinarySearchTree *tree, TYPE newValue);

int sizeBST(struct BinarySearchTree *tree);

struct Node *_nodeAddBST(struct Node *current, TYPE newValue);

int containsBST(struct BinarySearchTree *tree, TYPE d);

void removeBST(struct BinarySearchTree *tree, TYPE d);

TYPE _leftMostChild(struct Node *current);

struct Node *_removeLeftmostChild(struct Node *current);

struct Node *_nodeRemoveBST(struct Node *current, TYPE d);

#endif //WEEK_5_WORKSHEET_29_BST_H
