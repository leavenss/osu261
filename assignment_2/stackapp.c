/* CS261- Assignment 2 - Question 3
 * Name: Taylor Liss
 * Date: 10/8/17
 * Solution description: This application checks the balance of brackets, parenthesis and braces in an equation, using a stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    assert(s!= 0);
    DynArr *myArr;
    myArr = newDynArr(1);
	char newChar = nextChar(s);

    while (newChar != '\0'){
        if (newChar == '{') {
            pushDynArr(myArr, '}');
        } else if (newChar == '[') {
            pushDynArr(myArr, ']');
        } else if (newChar == '(') {
            pushDynArr(myArr, ')');
        } else if (newChar == '}' || newChar == ']' || newChar == ')') {
            if (isEmptyDynArr(myArr)){
                return 0;
            }
            if (newChar == topDynArr(myArr)) {
                popDynArr(myArr);
            } else {
                freeDynArr(myArr);
                return 0; //mismatched parenthesis
            }
        } else {
            newChar = nextChar(s);
            continue; //Non-parenthesis, bracket, brace found
        }
        newChar = nextChar(s);
    }
    if (isEmptyDynArr(myArr)) {
        freeDynArr(myArr);
        return 1;
    } else {
        freeDynArr(myArr);
        return 0;
    }
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

