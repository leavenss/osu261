/* CS261- Assignment 1 - Q.2*/
/* Name: Taylor Liss
 * Date: 9/24/17
 * Solution description: This program takes 3 variables and passes them into a function foo(). Two of the variables are
 * passed by reference. One of the variables is passed by value. The purpose is to show the difference between passing
 * by reference and passing by value in c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5, y = 6, z = 7;

    /*Print the values of x, y and z*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returned = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("foo() returned: %d\n", returned);

    /*Print the values of x, y and z again*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /*The returned value is different. When we passed in x and y, we were passing by reference, but when we passed
     * in z, we were passing by value, so a copy of the variable was passed in. The value was returned was 13, but
     * when we check the value stored in z, we see that it's still 7. x and y changed, but z did not. If we put this
     * statement in foo():
     *
     *          printf("a: %p\nb: %p\nc: %p\n", &*a, &*b, &c);
     *
     * and this statement in main():
     *
     *          printf("x: %p\ny: %p\nz: %p\n", &x, &y, &z);
     *
     * we can see that a and x share the same memory location, b and y share the same memory location, but c and
     * z have different memory locations. When we ran foo() were changing a copy of the value of the value stored at
     * z, not value of z itself.*/
    return 0;
}