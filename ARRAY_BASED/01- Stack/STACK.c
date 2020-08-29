
#include "STACK.h"

void InitializeStack(Stack *ps)
{
    ps -> top = 0;
    ps -> Size = 0;
}

int Push(StackEntry *pe,Stack *ps)
{
    ps -> entry[ps -> top ++] = *pe;
    ps -> Size++;
}

void Pop(StackEntry *pe,Stack *ps)
{
    *pe = ps -> entry[-- ps -> top];
    ps -> Size--;
}

int  StackEmpty(Stack *ps)
{
    return  !ps -> Size;
}

int  StackFull(Stack *ps)
{
    return ps -> top == MAXSTACK;
}

void ClearStack(Stack *ps)
{
    ps -> top = 0;
}
void StackTop(StackEntry *pe,Stack *ps)
{
    *pe = ps -> entry[ps -> top - 1];
}

int  StackSize(Stack *ps)
{
    return ps -> Size;
}

void TraverseStack(Stack *ps, void (*PF)(StackEntry e))
{
    int counter;
    for(counter = ps -> top;counter > 0;counter--)
    {
        (*PF)(ps -> entry[counter - 1]);
    }
}






