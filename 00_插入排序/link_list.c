#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// define a link list Node
typedef struct Node{
    int data;
    int *next;
} Node;

// define a link list 
typedef struct link_list{
    int *root;
    int length;
} link_list;

// create a link_list Node
Node *init_node(int value) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
}

// create a link_list
link_list *init_list(int *root) {
    link_list *p = (link_list*)malloc(sizeof(link_list));
    p->root = root;
    p->length = 0;
}

int main() {






    return 0;
}
