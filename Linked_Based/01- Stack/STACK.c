#include <stdlib.h>
#include "STACK.h"

void InitializeStack(Stack *ps)
{
    ps -> top = NULL;
    ps -> Size = 0;
}

int Push(StackEntry *pe,Stack *ps)
{
    StackNode *pn = (StackNode*) malloc(sizeof(StackNode));
    if(! pn)
    {
      return 0;
    }
    else
    {
    pn -> entry   = *pe;
    pn -> next    = ps -> top;
    ps -> top     = pn;
    ps -> Size++;
    return 1;
    }
}

void Pop(StackEntry *pe,Stack *ps)
{
    StackNode *pn = ps -> top;
    *pe = ps -> top -> entry;
    ps -> top = ps -> top -> next;
    free(pn);
    ps -> Size--;
}

int  StackEmpty(Stack *ps)
{
    return  !ps -> top;
}

int  StackFull(Stack *ps)
{
    return 0;
}

void ClearStack(Stack *ps)
{
    StackNode *pn;
    pn  = ps -> top;
    while(pn)
    {
        ps -> top = ps -> top -> next;
        free(pn);
        pn  = ps -> top;
    }
}
void StackTop(StackEntry *pe,Stack *ps)
{
    *pe = ps -> top -> entry;
}

int  StackSize(Stack *ps)
{
    return ps -> Size;
}

void TraverseStack(Stack *ps, void (*PF)(StackEntry e))
{
    for(StackNode *pn = ps -> top;pn;pn = pn -> next)
    {
        (*PF)(pn -> entry);
    }
}






