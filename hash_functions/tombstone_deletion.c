#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct {
    int key;
    int value;
    int state;
} Entry;

Entry table[SIZE];

int get(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {

        if (table[index].state == 0)
            return -1;

        if (table[index].state == 1 &&
            table[index].key == key) {
            return table[index].value;
        }

        index = (index + 1) % SIZE;
    }

    return -1;
}


void removeKey(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {

        // If state is EMPTY, stop.
        if (table[index].state == 0){
            return;
        }

        // If state is OCCUPIED and
        // the key matches, mark DELETED.
        if (table[index].state == 1 && table[index].key == key){
            table[index].state = 2;
            return;
        }

        // Otherwise move to next index.
        index = (index + 1) % SIZE;
    }
}
