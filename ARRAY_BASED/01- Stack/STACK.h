#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAXSTACK  5
typedef int       StackEntry;

typedef struct Stack
{
    int top;
    int Size;
    StackEntry entry[MAXSTACK];
}Stack;

void InitializeStack(Stack *ps);
int Push(StackEntry *pe,Stack *ps);
void Pop(StackEntry *pe,Stack *ps);
int  StackEmpty(Stack *ps);
int  StackFull(Stack *ps);
void ClearStack(Stack *ps);
void StackTop(StackEntry *pe,Stack *ps);
int  StackSize(Stack *ps);
void TraverseStack(Stack *ps, void (*PF)(StackEntry e));

#endif // STACK_H_INCLUDED
