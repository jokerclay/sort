#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MX_OP 10

/*
 * insert sort
 *
 * */


void insert_sort(int *unsort, int length) {
    
    int i, j, temp;

    for (i = 1; i < length; i++) {
        if(unsort[i] < unsort[i-1]) {

            temp = unsort[i];

            for( j = i -1; j >=0 && unsort[j] > temp; --j) {

                unsort[j+1] = unsort[j];

            }

            unsort[j+1] = temp;
        }
    }
}

int main() {

    int *unsort;

    srand(time(0));

    for (int i = 0; i < MX_OP; i++ ) {
        unsort[i] = rand()%100;
        printf("%d ", unsort[i]);
    }

    printf("\n");

    insert_sort(unsort, MX_OP);

    for (int i = 0; i < MX_OP; i++ ) {
        printf("%d ", unsort[i]);
    }

    return 0;
}









