/* CS261- Assignment 1 - Q. 0*/
/* Name: Taylor Liss
 * Date: 9/21/17
 * Solution description: This program assigns a value to x, then assigns a pointer to point to that variable. It prints
 * the value pointed to by the pointer, the address pointed to by the pointer, the address of the pointer itself, and
 * the value of x.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    /*Print the value pointed to by iptr*/
    printf("Value pointed to by iptr: %d\n", *iptr);
    /*Print the address pointed to by iptr*/
    printf("Address pointed to by iptr: %p\n", iptr);
    /*Print the address of iptr itself*/
    printf("Address of iptr itself: %p\n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 7;
    /*print the address of x*/
    printf("Address of x: %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("Value of x: %d\n", x);
    return 0;
}
