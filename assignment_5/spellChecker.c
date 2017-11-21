/* CS261- Assignment 5 - spellChecker.c: Spell Checker implementation.
 * Name: Taylor Liss
 * Date: 11/20/17
 * Solution description: This is my implementation of spell checker using a hashMap.
 */

#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char* dictWord = nextWord(file);
    while (dictWord != NULL){
        hashMapPut(map, dictWord, 1);
        free(dictWord);
        dictWord = nextWord(file);
    }
}

/*Code copied from https://www.lemoda.net/c/levenshtein/ */
static int distance(const char *word1,
                    int len1,
                    const char *word2,
                    int len2) {
    int matrix[len1 + 1][len2 + 1];
    int i;
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }
    for (i = 1; i <= len1; i++) {
        int j;
        char c1;

        c1 = word1[i - 1];
        for (j = 1; j <= len2; j++) {
            char c2;

            c2 = word2[j - 1];
            if (c1 == c2) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int delete;
                int insert;
                int substitute;
                int minimum;

                delete = matrix[i - 1][j] + 1;
                insert = matrix[i][j - 1] + 1;
                substitute = matrix[i - 1][j - 1] + 1;
                minimum = delete;
                if (insert < minimum) {
                    minimum = insert;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return matrix[len1][len2];
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);

    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);

        // Implement the spell checker code here..

        //Convert uppercase to lowercase
        for (int i = 0; i < 255; i++) {
            if (inputBuffer[i] > 64 && inputBuffer[i] < 91)
                inputBuffer[i] += 32;
        }

        if (strcmp(inputBuffer, "quit") == 0) {
            quit = 1;
        } else if (hashMapContainsKey(map, inputBuffer)) {
            printf("%s is spelled correctly. \n", inputBuffer);
        } else {
            HashLink *nextLink;
            int len1 = strlen(inputBuffer);
            int len2;
            int d;
            char *dictWord;
            int lowest = 200;

            //Runt through dictionary once to find lowest difference
            for (int i = 0; i < map->capacity; i++) {
                nextLink = map->table[i];
                while (nextLink != NULL) {
                    dictWord = nextLink->key;
                    len2 = strlen(dictWord);
                    d = distance(inputBuffer, len1, dictWord, len2);
                    if (d < lowest){
                        lowest = d;
                    }
                    nextLink = nextLink->next;
                }
            }

            //Run through dictionary again to get the first 10 words that have lowest difference

            int printCount = 0;
            int printMax = 10;
            printf("Word not found. Maybe you meant:\n");
            for (int i = 0; i < map->capacity; i++) {
                nextLink = map->table[i];
                while (nextLink != NULL) {
                    if (printCount == printMax){
                        break;
                    }
                    dictWord = nextLink->key;
                    len2 = strlen(dictWord);
                    d = distance(inputBuffer, len1, dictWord, len2);
                    if (d == lowest){
                        printf("%s\n", dictWord);
                        printCount++;
                    }
                    nextLink = nextLink->next;
                }
            }
        }
    }

    hashMapDelete(map);
    return 0;
}