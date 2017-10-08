#ifndef WEEK_3_WORKSHEET_20_DYNAMICARRAYBAG_H
#define WEEK_3_WORKSHEET_20_DYNAMICARRAYBAG_H

#define TYPE int

#ifndef EQ
#define EQ(a, b) (a == b)
#endif

struct deque {
    TYPE * data;
    int capacity;
    int size;
    int beg;
};

void _dequeSetCapacity (struct deque *d, int newCap);

void dequeFree (struct deque *d);

void dequeInit (struct deque *d, int initCapacity);

int dequeSize (struct deque *d);

void dequeAddFront (struct deque *d, TYPE newValue);

void dequeAddBack (struct deque *d, TYPE newValue);

TYPE dequeFront (struct deque *d);

TYPE dequeBack (struct deque *d);

void dequeRemoveFront (struct deque *d);

void dequeRemoveBack (struct deque *d);

#endif //WEEK_3_WORKSHEET_20_DYNAMICARRAYBAG_H
