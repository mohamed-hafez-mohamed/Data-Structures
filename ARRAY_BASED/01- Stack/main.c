#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"

int main()
{
    Stack MyStack;
    StackEntry element = 10;
    StackEntry top_element;

    InitializeStack(&MyStack);
    if(!StackFull(&MyStack))
    {
        Push(&element,&MyStack);
    }
    if(!StackEmpty(&MyStack))
    {
        StackTop(&top_element, &MyStack);
    }
    printf("FIRST ELEMENT = %d\n",element);
    printf("TOP   ELEMENT = %d\n",top_element);
    return 0;
}
