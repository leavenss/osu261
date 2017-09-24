/* CS261- Assignment 1 - Q.3*/
/* Name: Taylor Liss
 * Date: 9/24/17
 * Solution description: This program dynamically creates an array of random integers from 0-100 inclusive. It then
 * sorts that array using a selection sort algorithm.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include <time.h>


void sort(int* number, int n){
    /*Sort the given array number , of length n*/
    //Selection sort
    int i;
    for (i=0; i < n; i++){
        int index_of_min = i;
        for(int j=i; j < n; j++){
            if(number[index_of_min] > number[j]) {
                index_of_min = j;
            }
        }
        int temp = number[i];
        number[i] = number[index_of_min];
        number[index_of_min] = temp;
    }
}

int main(){
    int NUMMAX = 100;
    int i;
    int newRandomNum;
    time_t t;
    srand((unsigned) time(&t));

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *myArray = malloc(n * sizeof(int));
    assert(myArray != 0);

    /*Fill this array with random numbers, using rand().*/
    for (i=0; i < n; i++) {
        newRandomNum = (rand() % NUMMAX) + 1;
        myArray[i] = newRandomNum;
    }

    /*Print the contents of the array.*/
    printf("Unsorted: ");
    for (i=0; i < n; i++){
        printf("%d ", myArray[i]);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(myArray, n);

    /*Print the contents of the array.*/
    printf("Sorted: ");
    for (i=0; i < n; i++){
        printf("%d ", myArray[i]);
    }
    printf("\n");

    free(myArray);
    return 0;
}
