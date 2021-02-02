#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STACK_interface.h"

int main()
{
    Stack_t      MyStack;
    StackEntry_t element = 10;
    StackEntry_t top_element;

    STACK_voidInitializeStack(&MyStack);
    if(!STACK_u8IsStackFull(&MyStack))
    {
        STACK_u8PushEntryElement(&element,&MyStack);
    }
    if(!STACK_u8IsStackEmpty(&MyStack))
    {
        STACK_u8PopEntryElement(&top_element, &MyStack);
    }
    printf("FIRST ELEMENT = %d\n",element);
    printf("TOP   ELEMENT = %d\n",top_element);
    return 0;
}
