#include <stdio.h>
#include <stdbool.h>

#define SIZE 7

typedef struct {
    int key;
    int value;
    bool occupied;
} Entry;

Entry table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void put(int key, int value) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {

        if (!table[index].occupied ||
            table[index].key == key) {

            table[index].key = key;
            table[index].value = value;
            table[index].occupied = true;

            return;
        }

        index = (index + 1) % SIZE;
    }

    printf("Hash table is full!\n");
}


int get(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++){
        
        if (table[index].occupied && table[index].key == key){
            return table[index].value;
        }
        index = (index + 1) % SIZE;
    }
    return -1;

}
  