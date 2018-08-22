#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 1024
#define MAXNM 64

typedef struct stack_node{
    int value;
    char * name;
    struct stack_node * next;
}stack_node;

typedef struct stack{
    int size;
    stack_node * top;
}stack;

stack * create_stack();

stack_node * push_stack(stack * s, int value, char * name);

stack_node * pop_stack(stack * s);

void free_node(stack_node * n);

void free_stack(stack * s);

void enter_data(stack * s, stack_node * node);

void print_stack(stack * s, stack_node * node);

