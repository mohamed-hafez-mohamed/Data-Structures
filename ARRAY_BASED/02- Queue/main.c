#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "QUEUE_interface.h"

int main()
{
    Queue_t      MyQueue;
    QueueEntry_t element = 10;
    QueueEntry_t front_element;

    QUEUE_voidInitializeQUEUE(&MyQueue);
    if(!QUEUE_u8IsQueueFull(&MyQueue))
    {
        QUEUE_u8AppendElement(&element,&MyQueue);
    }
    if(!QUEUE_u8IsQueueEmpty(&MyQueue))
    {
        Queue_voidServeElement(&front_element, &MyQueue);
    }
    printf("FIRST   ELEMENT = %d\n",element);
    printf("FRONT   ELEMENT = %d\n",front_element);
    return 0;
}
