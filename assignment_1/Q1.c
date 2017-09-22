/* CS261- Assignment 1 - Q.1*/
/* Name: Taylor Liss
 * Date: 9/22/17
 * Solution description:
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <stdbool.h>

struct student{
    int id;
    int score;
};

struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student *myStudents = malloc(10 * sizeof(struct student));
    /*return the pointer*/
    return myStudents;
}

bool isUniqueInArray(int idArray[10], int elementsInArray, int compareNum){

    int i, j;

    //Selection sort
    for (i=0; i < elementsInArray; i++){
        int index_of_min = i;
        for(j=i; j < elementsInArray; j++){
            if(idArray[index_of_min] > idArray[j]) {
                index_of_min = j;
            }
        }
        int temp = idArray[i];
        idArray[i] = idArray[index_of_min];
        idArray[index_of_min] = temp;
    }

    //Linear search
    for (i=0; i < elementsInArray; i++){
        printf("%d vs %d\n"), idArray[i], compareNum;
        if (idArray[i] != compareNum){
            return true;
        } else {
            return false;
        }
    }
}

void generate(struct student* students){
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int IDMAX = 10;
    int SCOREMAX = 100;
    int i;
    int elementsInArray = 0;
    int newRandomNum;
    time_t t;
    int idArray[10];

    srand((unsigned) time(&t));

    //Generate a  random number and add it to the array.
    for (i=0; i < 10; i++) {
        newRandomNum = rand() % (IDMAX+1);
        printf("newRandomNum is %d\n Unique? %d\n",newRandomNum, isUniqueInArray(idArray, 10, newRandomNum));
        if (isUniqueInArray(idArray, 10, newRandomNum) == true){
            idArray[elementsInArray] = newRandomNum;
            elementsInArray++;
        }
    }

    printf("Here's the array:\n");
    for (i=0; i < elementsInArray; i++) {
        printf("%d ", idArray[i]);
    }
}

void output(struct student* students){
    /*Output information about the ten students in the format:
             ID1 Score1
             ID2 score2
             ID3 score3
             ...
             ID10 score10*/
}

void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/

}

void deallocate(struct student* stud){
    /*Deallocate memory from stud*/
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/

    /*call summary*/

    /*call deallocate*/

    return 0;
}
