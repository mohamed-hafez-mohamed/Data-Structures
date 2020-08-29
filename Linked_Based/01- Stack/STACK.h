#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDE

#define MAXSTACK  5
typedef int       StackEntry;

typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;
}StackNode;

typedef struct Stack
{
    StackNode *top;
    int Size;
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
