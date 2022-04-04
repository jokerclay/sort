#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_OP 30

void insert_sort_1(int *unsorted, int unsorted_array_length) {
    printf("\n--== 普通(temp)模式 ==--\n");
    int i, j, temp;
    for (i = 1; i < unsorted_array_length; i++) {
        if (unsorted[i] < unsorted[i - 1]) {
            temp = unsorted[i];

            for (j = i - 1; j >=0 && unsorted[j] >temp; --j) {
                unsorted[j+1] = unsorted[j];
            }

            unsorted[j+1] = temp;
        }
    }
}



// 哨兵模式
void insert_sort_2(int *unsorted, int unsorted_array_length) {
    printf("\n--== 哨兵模式 ==--\n");

    int i, j;
    for (i = 2; i <= unsorted_array_length; i++) {
        if (unsorted[i] < unsorted[i - 1]) {
            unsorted[0] = unsorted[i];
            for (j = i - 1; unsorted[0] < unsorted[j]; --j) {
                unsorted[j+1] = unsorted[j];
            }
            unsorted[j+1] = unsorted[0];
        }
    }
}




int main() {

    int *unsorted_array;

    srand(time(0));

    for (int i = 0; i < MAX_OP; i++) {
        unsorted_array[i] = rand()%100;
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

    // 插入排序
    
    // 普通(temp)模式
    // insert_sort_1(unsorted_array, MAX_OP);

    // 哨兵模式
    insert_sort_2(unsorted_array, MAX_OP);


    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", unsorted_array[i]);
    }
    printf("\n");

    return 0;
}

