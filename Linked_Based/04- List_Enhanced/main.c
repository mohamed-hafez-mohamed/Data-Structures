#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"

int main()
{
    List MyList;
    ListEntry element = 10;
    ListEntry front_element;

    InitializeList(&MyList);
    if(!ListFull(&MyList))
    {
        Insert(0,&element,&MyList);
    }
    if(!ListEmpty(&MyList))
    {
        Delete(0,&front_element, &MyList);
    }
    printf("FIRST   ELEMENT = %d\n",element);
    printf("FRONT   ELEMENT = %d\n",front_element);
    return 0;
}
