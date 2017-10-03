#ifndef WEEK_2_WORKSHEET_21_DYNAMICARRAYBAG_H
#define WEEK_2_WORKSHEET_21_DYNAMICARRAYBAG_H

#define TYPE int

#ifndef EQ
#define EQ(a, b) (a == b)
#endif

struct DynArr {
    TYPE * data;
    int size;
    int capacity;
};

/* initialize a dynamic array structure with given capacity */
void initDynArr (struct DynArr * da, int initialCapacity);

/* internal method to double the capacity of a dynamic array */
void _setCapacityDynArr (struct DynArr *v, int newCap);

/* release dynamically allocated memory for the dynamic array */
void freeDynArr (struct DynArr * da);

/* return number of elements stored in dynamic array */
int sizeDynArr (struct DynArr * da);

/* add a value to the end of a dynamically array */
void addDynArr (struct DynArr * da, TYPE e);

/* remove the value stored at position in the dynamic array */
void removeAtDynArr (struct DynArr * da, int position);

/* retrieve element at a given position */
TYPE getDynArray (struct DynArr * da, int position);

/* store element at a given position */
void putDynArr (struct DynArr * da, int position, TYPE value);

/* Check if array is empty */
int isEmptyDynArray (struct DynArr * da);

void _dynArrayRemoveAt (struct DynArr * da, int index);

#endif //WEEK_2_WORKSHEET_21_DYNAMICARRAYBAG_H
