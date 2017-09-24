/* CS261- Assignment 1 - Q.4*/
/* Name: Taylor Liss
 * Date: 9/24/17
 * Solution description: This program generates 10 students with unique ids from 1 to 10 inclusive. It gives them each
 * a random score from 0 to 100 inclusive. It prints out the students and their scores unordered, then uses a selection
 * sort algorithm to sort the students in ascending order based on score.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

struct student{
    int id;
    int score;
};

void sort(struct student* students, int n){
    int i, j;
    /*Sort the n students based on their score*/
    for (i = 0; i < n; i++){
        int index_of_min = i;
        for(j=i; j < n; j++){
            if(students[index_of_min].score > students[j].score) {
                index_of_min = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[index_of_min];
        students[index_of_min] = temp;
    }
}

/*Function to determine if an ID number is unique in an array.*/
bool isUniqueInArray(const int *idArray, int elementsInArray, const int *compareNum){
    int i;
    bool unique = true;
    //Linear search
    for (i=0; i < elementsInArray; i++){
        if (idArray[i] == *compareNum){
            unique = false;
        }
    }
    return unique; // if its the first item in the array
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *myStudents = malloc(10 * sizeof(struct student));
    assert(myStudents != 0);

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    int IDMAX = 10;
    int SCOREMAX = 100;
    int i;
    int newRandomNum;
    time_t t;
    int idArray[n];
    int scoreArray[n];
    srand((unsigned) time(&t));

    for (i=0; i < n; i++) {
        newRandomNum = (rand() % IDMAX)+1;
        while(isUniqueInArray(idArray, i, &newRandomNum) == false){
            newRandomNum = (rand() % IDMAX)+1;
        }
        idArray[i] = newRandomNum;
        newRandomNum = rand() % (SCOREMAX+1);
        scoreArray[i] = newRandomNum;
        myStudents[i].id = idArray[i];
        myStudents[i].score = scoreArray[i];
    }

    /*Print the contents of the array of n students.*/
    printf("Unsorted:\n");
    for (i = 0; i < n; i++){
        printf("%3d\t%3d\n", myStudents[i].id, myStudents[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(myStudents, n);

    /*Print the contents of the array of n students.*/
    printf("Sorted:\n");
    for (i = 0; i < n; i++){
        printf("%3d\t%3d\n", myStudents[i].id, myStudents[i].score);
    }

    return 0;
}
