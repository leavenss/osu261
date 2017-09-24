/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
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
        if (i % 2 == 1 && word[i] >= 'a' && word[i] <= 'z') {
            printf("Running toUpper\n");
            word[i] = toUpperCase(word[i]);
        } else if (i % 2 == 0 && word[i] >= 'A' && word[i] <= 'Z'){
            printf("Running toLower\n");
            word[i] = toLowerCase(word[i]);
        } else if (i % 2 == 0 || i % 2 == 1) { //Todo fix this statement
        } else {
            break;
        }
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char myString[20];
    scanf("%s", myString);

    /*Call sticky*/
    sticky(myString);

    /*Print the new word*/
    printf("%s", myString);

    return 0;
}
