/* CS261- Assignment 1 - Q.5*/
/* Name: Taylor Liss
 * Date: 9/24/17
 * Solution description: This program asks the user to input a word and then returns the word in sticky caps. It can
 * accept a word up to 20 characters long.
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
    return ch-'A'+'a';
}

void sticky(char* word){
    /*Convert to sticky caps*/
    for (int i=0; i<20; i++){
        if (i % 2 == 0 && word[i] >= 'a' && word[i] <= 'z') { //if the character is odd and lowercase
            word[i] = toUpperCase(word[i]);
        } else if (i % 2 == 1 && word[i] >= 'A' && word[i] <= 'Z'){
            word[i] = toLowerCase(word[i]);
        } else if (i % 2 == 0 && word[i] >= 'A' && word[i] <= 'Z'
                   || i % 2 == 1 && word[i] >= 'a' && word[i] <= 'z') {
            continue;
        } else {
            break;
        }
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char myString[20];
    printf("Enter a word up to 20 characters long:\n");
    scanf("%s", myString);

    /*Call sticky*/
    sticky(myString);

    /*Print the new word*/
    printf("%s", myString);

    return 0;
}
