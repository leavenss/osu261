/*
 * CS 261 Data Structures
 * Assignment 5
 * Name: 
 * Date: 
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink* link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map)
{
    // FIXME: implement
    HashLink *linkIterator;
    HashLink *nextLink;

    for (int i = 0; i < map->capacity; i++)
    {
        nextLink = map->table[i];
        while (nextLink != NULL){
            linkIterator = nextLink->next;
            hashLinkDelete(nextLink);
            nextLink = linkIterator;
        }
    }
    free(map->table);
    map->size = 0;
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key)
{
    // FIXME: implement
    int hashKey = HASH_FUNCTION(key) % map->capacity;
    HashLink* foundLink = map->table[hashKey];

    while (foundLink != NULL) {
        if (strcmp(foundLink->key, key) == 0){
            return &foundLink->value;
        }
        foundLink = foundLink->next;
    }
    return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity. After allocating the new table, all of the links need to be
 * rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity)
{
    // FIXME: implement
    //Create new hashmap with the correct size
    HashMap* newMap = hashMapNew(capacity);
    HashLink* tempLink;

    int prevCapacity = hashMapCapacity(map);


    for (int i=0; i < prevCapacity; i++){
        tempLink = map->table[i];

        //Copy each link over to the new map
        while (tempLink != NULL){
            hashMapPut(newMap, tempLink->key, tempLink->value);
            tempLink = tempLink->next;
        }
    }
    //Remove all the old links
    hashMapCleanUp(map);
    //Update the old map's values with the values from the new map
    map->table = newMap->table;
    map->size = newMap->size;
    map->capacity = capacity;


    //Now newMap's table and map's table are pointing to the same table.
    //Set newMap's table to NULL so only map is pointing to table.
    newMap->table = NULL;
    //Now when we free newMap, we don't lose the table that map is pointing to.
    free(newMap);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value)
{
    // FIXME: implement

    printf("KVH: %c - %d - %d\n",*key, value, (HASH_FUNCTION(key)%map->capacity));

    if (key != NULL){
        int mapLocation = HASH_FUNCTION(key) % map->capacity;
        HashLink* linkIterator = map->table[mapLocation];

        //Check for an existing link with the given key
        int* currentValue = hashMapGet(map, key);
        //If the key exists, replace its value with the new value
        if (currentValue != NULL) {
            *currentValue += value;
        } else {
            //else if the key does not exist, create a new link
            HashLink *newLinkToAdd = hashLinkNew(key, value, 0);
            //if the mapLocation has no links, add the new link
            if (map->table[mapLocation] == NULL) {
                map->table[mapLocation] = newLinkToAdd;
            } else {
                //else if the mapLocation has links (and none of
                //them correlate to the key), add link to the end.
                while (linkIterator->next != NULL){
                    linkIterator = linkIterator->next;
                }
                linkIterator->next = newLinkToAdd;
            }
            map->size = map->size + 1;
        }
        //check if you need to resize
        float currentLoad = hashMapTableLoad(map);
        if (currentLoad >= MAX_TABLE_LOAD){
            resizeTable(map, 2 * map->capacity);
        }
    }
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key)
{
    // FIXME: implement
    int mapLocation = HASH_FUNCTION(key) % map->capacity;
    HashLink *linkIterator = map->table[mapLocation];
    HashLink *tempLink = NULL;

    if (linkIterator != NULL){
        //if the first link is the one we are looking for
        if (strcmp(linkIterator->key, key) == 0){
            //set the first link to the next link
            map->table[mapLocation] = linkIterator->next;
        } else {
            //start searching though links until we get a match
            while(linkIterator->key != key){
                tempLink = linkIterator;
                linkIterator = linkIterator->next;
            }
            //link the previous link to the one after linkIterator
            tempLink->next = linkIterator->next;
        }
        hashLinkDelete(linkIterator);
        map->size = map->size - 1;
    }
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key)
{
    // FIXME: implement
    int mapLocation = HASH_FUNCTION(key) % map->capacity;
    HashLink *linkIterator = map->table[mapLocation];

    if (mapLocation < 0){
        mapLocation = mapLocation + map->capacity;
    }

    while (linkIterator != NULL){
        printf("linkIterator->key is %c and key is %c\n", *linkIterator->key, *key);
        if (strcmp(key, linkIterator->key) == 0){
            printf("gonna return a 1\n");
            return 1;
        }
        linkIterator = linkIterator->next;
    }
    printf("gonna return a 0\n");
    return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map)
{
    // FIXME: implement
    return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map)
{
    // FIXME: implement
    return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map)
{
    // FIXME: implement
    int bucketCount = 0;
    for (int i=0; i < map->capacity; i++){
        if (map->table[i] == NULL){
            bucketCount = bucketCount + 1;
        }
    }
    return bucketCount;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map)
{
    // FIXME: implement
    float mapSize = (float)map->size;
    float mapCap = (float)map->capacity;
    float load = mapSize/mapCap;
    return load;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        HashLink* link = map->table[i];
        if (link != NULL)
        {
            printf("\nBucket %i ->", i);
            while (link != NULL)
            {
                printf(" (%s, %d) ->", link->key, link->value);
                link = link->next;
            }
        }
    }
    printf("\n");
}