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

int NUMOFSTUDENTS = 10;

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

bool isUniqueInArray(const int *idArray, int elementsInArray, const int *compareNum){
    bool unique = true;
    //Linear search
    for (int i=0; i < elementsInArray; i++){
        if (idArray[i] == *compareNum){
            unique = false;
        }
    }
    return unique; // if its the first item in the array
}

void generate(struct student* students){
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int IDMAX = 10;
    int SCOREMAX = 100;
    int NUMSTUDENTS = 10;
    int i;
    int newRandomNum;
    time_t t;
    int idArray[10];
    int scoreArray[10];

    srand((unsigned) time(&t));

    //Generate 10 unique ID numbers between 1 and 10 inclusive and 10 random scores between 0 and 100 inclusive
    for (i=0; i < NUMOFSTUDENTS; i++) {
        newRandomNum = (rand() % IDMAX)+1;
        while(isUniqueInArray(idArray, i, &newRandomNum) == false){
            newRandomNum = (rand() % IDMAX)+1;
        }
        idArray[i] = newRandomNum;
        newRandomNum = rand() % (SCOREMAX+1);
        scoreArray[i] = newRandomNum;
        students[i].id = idArray[i];
        students[i].score = scoreArray[i];
    }
}

void output(struct student* students){
    /*Output information about the ten students in the format:
             ID1 Score1
             ID2 score2
             ID3 score3
             ...
             ID10 score10*/
    for (int i = 0; i < NUMOFSTUDENTS; i++){
        printf("%d, %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    int minimum = 100;
    int maximum = 0;
    float average = 0;

    for (int i = 0; i < NUMOFSTUDENTS; i++){
        if (students[i].score < minimum){
            minimum = students[i].score;
        }
        if (students[i].score > maximum){
            maximum = students[i].score;
        }
        average += students[i].score;
    }
    average = average / NUMOFSTUDENTS;

    printf("Lowest score is: %d\n", minimum);
    printf("Highest score is: %d\n", maximum);
    printf("Average score is: %f\n", average);
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
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
