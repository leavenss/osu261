#ifndef WEEK_2_WORKSHEET_0_ARRAYBAGSTACK_H
#define WEEK_2_WORKSHEET_0_ARRAYBAGSTACK_H

#define TYPE int
#define  EQ(a, b) (a == b)

/*bag interface*/
void initArray(struct arrayBagStack * b);
void addArray(struct arrayBagStack * b, TYPE v);
int containsArray(struct arrayBagStack * b, TYPE v);
void removeArray(struct arrayBagStack * b, TYPE v);
int sizeArray(struct arrayBagStack * b);

/*stack interface*/
void pushArray (struct arrayBagStack * b, TYPE v);
TYPE topArray (struct arrayBagStack * b);
void popArray (struct arrayBagStack * b);
int isEmptyArray (struct arrayBagStack * b);

#endif //WEEK_2_WORKSHEET_0_ARRAYBAGSTACK_H
