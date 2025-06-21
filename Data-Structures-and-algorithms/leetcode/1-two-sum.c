#include <stdio.h>
#include <stdlib.h>


typedef struct HashNode {
    int key;
    int val;
    struct HashNode* next;
} HashNode;

hashNode* hashTable[10000];

int hash(int key) {
    return abs(key) % 10000
}

void insert(int key, int val) {
    int idx hash(key);
    hashNode* node = (HashNode*)malloc(sizeof(HashNode));

    node->key = key;
    node->val = val;
    node->next = hashTable[idx];
    hashTable[idx] = node;
}

int find(int key, int* val) {
    int idx = hash(key);
    hashNode* node = hashTable[idx];
    while(node) {
        if (node->key == key) {
            *val = node->val;
            return 1;
        }
        node = node->next;
    }
    return 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
}