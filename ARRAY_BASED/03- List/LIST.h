#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string.h>

typedef int      KeyType;
typedef struct elementtype
{
   KeyType key;
}ElementType;

#ifdef KeyType String
   #define EQ(a, b) (!strcmb((a),(b)))
   #define LT(a, b) (strcmb((a),(b)) < 0)
   #define LE(a, b) (strcmb((a),(b)) <= 0)
   #define GT(a, b) (strcmb((a),(b)) > 0)
   #define GE(a, b) (strcmb((a),(b)) >= 0)
#else
   #define EQ(a, b) ((a) == (b))
   #define LT(a, b) ((a) <  (b))
   #define LE(a, b) ((a) <= (b))
   #define GT(a, b) ((a) >  (b))
   #define GE(a, b) ((a) >= (b))
#endif // KeyType

#define MAXLIST     5
typedef ElementType ListEntry;

typedef struct List
{
   int Size;
   ListEntry entry[MAXLIST];
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
int  SequentialSearch(KeyType target, List *pl);
void InsertOrder(ListEntry *pe,List *pl);
int Binary2Search(KeyType k, List *pl);

#endif // LIST_H_INCLUDED
