#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

Node *table[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void put(int key, int value) {
    int index = hash(key);

    Node *curr = table[index];

    while (curr != NULL) {
        if (curr->key == key) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
        return;

    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int get(int key) {
    int index = hash(key);

    Node *curr = table[index];

    while (curr != NULL){
        if (curr->key == key){
            return curr->value;
        }
        curr = curr->next;
    }
    return -1;
}