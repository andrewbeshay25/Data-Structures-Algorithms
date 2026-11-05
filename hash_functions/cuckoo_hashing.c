#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define MAX_KICKS 20

int table1[SIZE];
int table2[SIZE];

int occupied1[SIZE] = {0};
int occupied2[SIZE] = {0};

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return (key / SIZE) % SIZE;
}


void put(int key) {
    int current = key;

    // Assume key is not already stored.

    for (int i = 0; i < MAX_KICKS; i++) {

        // Try inserting into Table 1
        int index = hash1(current);

        if (!occupied1[index]) {
            table1[index] = current;
            occupied1[index] = 1;
            return;
        }

        // Kick out the existing key
        int old = table1[index];
        table1[index] = current;
        current = old;

        // Try inserting into Table 2
        index = hash2(current);

        if (!occupied2[index]) {
            table2[index] = current;
            occupied2[index] = 1;
            return;
        }

        // Kick out the existing key
        old = table2[index];
        table2[index] = current;
        current = old;
    }

    printf("Too many collisions! Rehash needed.\n");
}

