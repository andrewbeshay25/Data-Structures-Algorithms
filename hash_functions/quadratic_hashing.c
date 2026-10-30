#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

typedef struct {
    int key;
    int value;
    int occupied;
} Entry;

Entry table[SIZE];

int hash(int key) {
    return key % SIZE;
}


void put(int key, int value) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + (i*i)) % SIZE;

        if (!table[newIndex].occupied || table[newIndex].key == key){
            
            table[newIndex].key = key;
            table[newIndex].value = value;
            table[newIndex].occupied = 1;
            
            return;
        }
    }

    printf("Insertion failed!\n");
}
