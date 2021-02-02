#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LIST_interface.h"

int main()
{
    List_t      MyList;
    ListEntry_t element;
    element.key = 10;
    ListEntry_t front_element;
    LIST_voidInitializeList(&MyList);
    if(!LIST_u8IsListFull(&MyList))
    {
        LIST_u8InsertElement(0,&element,&MyList);
    }
    if(!LIST_u8IsListEmpty(&MyList))
    {
        LIST_u8DeleteElement(0,&front_element, &MyList);
    }
    printf("FIRST   ELEMENT = %d\n",element.key);
    printf("FRONT   ELEMENT = %d\n",front_element);
    return 0;
}
