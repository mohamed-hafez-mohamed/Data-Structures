#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MAXLIST  5
typedef int      ListEntry;

typedef struct Listnode
{
    ListEntry entry;
   struct Listnode *next;
   struct Listnode *previous;
}ListNode;

typedef struct List
{
   int Size;
   int currentPos;
   ListNode *current;
}List;

void InitializeList(List *pl);
int  Insert(int pos,ListEntry *pe,List *pl);
void Delete(int pos,ListEntry *pe,List *pl);
void  Retrieve(int pos,ListEntry *pe,List *pl);
void Replace(int pos,ListEntry *pe,List *pl);
int  ListEmpty(List *pl);
int  ListFull(List *pl);
int  ListSize(List *pl);
void ClearList(List *pl);
void TraverseList(List *pl, void (*PF)(ListEntry e));

#endif // LIST_H_INCLUDED
