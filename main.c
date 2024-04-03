#include "main.h"

int main(void)
{
    stack * s = create_stack();
    stack_node * node = NULL;

    printf("            // STACK PROGRAM // \n\n");
    printf("|| The first node in will be the last one out \n");
    printf("|| Each stack node contains a integer value and a string \n");
    printf("|| Submitting an empty integer value will cause the input process to finish (zero is not an empty value)\n\n\n");

    enter_data(s,node);

    print_stack(s, node);

    printf("\n--- press any key to quit program --- ");
    getchar();

    return 0;
}
