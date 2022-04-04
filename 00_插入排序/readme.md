# C 版本
```C
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
```

# C++ 版本
```C++
// 插入排序
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// 插入排序
void sort(std::vector<int> &values) {
  // For each element not in the sorted sub-vector
  // Skip first element (sorted sub-vector contains only a single element)
  for (auto to_insert = 1u; to_insert < values.size(); to_insert++) {
    // Start comparing elements starting at the element we want to insert
    auto current = to_insert;

    // While the current element is not the first in sub-vector
    while (current > 0) {
      // We compare the current element to the previous in the sub-vector
      auto prev = current - 1;

      // Exit when we reach the insertion point
      // (When the prev element is smaller)
      if (values[prev] <= values[current]) break;

      // Swap the smaller element downward
      std::swap(values[prev], values[current]);

      // Move the current element to compare over
      current--;
    }
  }
}

// 打印出 vector 中的内容
void print(const std::vector<int> &values) {
  for (auto v : values) std::cout << v << ' ';
  std::cout << '\n';
}

int main() {
  // Number of elements to sort
  int N = 16;

  // Create our random number generator
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 100);

  // Create vector of input elements
  std::vector<int> values;
  values.reserve(N);
  for (int i = 0; i < N; i++) values.push_back(dist(rng));

  // Print out starting values
  print(values);

  // Sort the vector
  sort(values);

  // Print ending values
  print(values);

  return 0;
}

/*
 * 总结:
 * 插入排序:
 * 从头开始两两比较向后走，
 * 比大小，向前看，小的向前插到合适的位置
 *
 * */

```
