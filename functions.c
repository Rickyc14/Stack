#include "main.h"

stack * create_stack(){
    stack * s = malloc(sizeof * s);
    if(!s){
        perror("malloc-s");
        return NULL;
    }
    s->size=0;
    s->top=NULL;
    return s;
}

stack_node * push_stack(stack * s, int value, char * name){
    stack_node * n = malloc(sizeof * n);
    if(!n){
        perror("malloc-n");
        return NULL;
    }
    n->value=value;
    n->name = malloc(strlen(name) + 1);
    if(!n->name){
        perror("malloc-name");
        return NULL;
    }
    strcpy(n->name,name);
    n->next = s->top;
    s->top = n;
    s->size++;
    return n;
}

stack_node * pop_stack(stack * s){
    if(s->size>0){
        stack_node * node = s->top;
        s->top=s->top->next;
        s->size--;
        return node;
    }
    return NULL;
}

void free_node(stack_node * n){
    if(n->name)
        free(n->name);
    free(n);
}

void free_stack(stack * s){
    while(s->size > 0){
        stack_node * victim = s->top;
        s->top=s->top->next;
        free_node(victim);
        s->size--;
    }
    free(s);
}

void enter_data(stack * s, stack_node * node){
for(;;){
        char buf[MAXC] = "";
        char name[MAXNM] = "";
        int value = 0;
        for(;;){
            fputs("\nenter value: ",stdout);
            if(fgets(buf,MAXC,stdin)){
                if(*buf == '\n'){
                    fputs("*input done*",stderr);
                    goto inputdone;
                }
                if(sscanf(buf,"%d",&value)==1){
                    break;
                }else{
                    fputs("*invalid input*\n",stderr);
                }
            }else{
                fputs("*user canceled input*",stderr);
                goto inputdone;
            }
        }
        for(;;){
            fputs("enter name: ",stdout);
            if(fgets(name,MAXNM,stdin)){
                size_t len = strlen(name);
                if(len && name[len-1] == '\n'){
                        name[--len] = 0;
                    if(len)
                        break;
                    else
                        fputs("error: empty-line.",stderr);
                }else if(len == MAXNM - 1){
                    fputs("error: name truncated.",stderr);
                }
            }else{
                fputs("*user canceled input*",stderr);
                goto inputdone;
            }
        }
        push_stack(s,value,name);
    }
    inputdone:;
}

void print_stack(stack * s, stack_node * node){
    puts("\n\n|| STACK DATA ||\n");

    while((node = pop_stack(s)) != NULL){
        printf("value: %2d      name: %s \n",node->value,node->name);
        free_node(node);
    }
    free_stack(s);
}
