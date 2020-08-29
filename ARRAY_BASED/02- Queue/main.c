#include <stdio.h>
#include <stdlib.h>
#include "QUEUE.h"

int main()
{
    Queue MyQueue;
    QueueEntry element = 10;
    QueueEntry front_element;

    InitializeQueue(&MyQueue);
    if(!QueueFull(&MyQueue))
    {
        Append(&element,&MyQueue);
    }
    if(!QueueEmpty(&MyQueue))
    {
        Serve(&front_element, &MyQueue);
    }
    printf("FIRST   ELEMENT = %d\n",element);
    printf("FRONT   ELEMENT = %d\n",front_element);
    return 0;
}
