#include "LIST.h"

void InitializeList(List *pl)
{
    pl -> Size  = 0;
}

int  Insert(int pos,ListEntry *pe,List *pl)
{
    int i;
    for(i = pl -> Size - 1;i >= pos;i--)
    {
        pl -> entry[i + 1] = pl -> entry[i];
    }
    pl -> entry[pos] = *pe;
    pl -> Size++;
}

void Delete(int pos,ListEntry *pe,List *pl)
{
    int i;
    *pe = pl -> entry[pos];
    for(i = pos + 1;i <= pl -> Size - 1;i++)
    {
        pl -> entry[i - 1] = pl -> entry[i];
    }
    pl -> Size--;
}

void  Retrieve(int pos,ListEntry *pe,List *pl)
{
    *pe = pl -> entry[pos];
}

void Replace(int pos,ListEntry *pe,List *pl)
{
    pl -> entry[pos] = *pe;
}

int  ListEmpty(List *pl)
{
    return !pl -> Size;
}

int  ListFull(List *pl)
{
    return (pl -> Size == MAXLIST);
}

int  ListSize(List *pl)
{
    return pl -> Size;
}

void ClearList(List *pl)
{
    pl -> Size  = 0;
}

void TraverseList(List *pl, void (*PF)(ListEntry e))
{
    int pos;
    for(pos = 0;pos < pl -> Size;pos++)
    {
        (*PF)(pl -> entry[pos]);
    }
}

int  SequentialSearch(KeyType target, List *pl)
{
    int current, s = ListSize(pl);
    ListEntry currententry;
    for(current = 0;current < s;current++)
    {
        Retrieve(current,&currententry,pl);
        if(EQ(target,currententry.key))
        {
            return current;
        }
    }
    return -1;
}

void InsertOrder(ListEntry *pe,List *pl)
{
    int current , s = ListSize(pl);
    ListEntry currententry;
    for(current = 0;current < s;current++)
    {
        Retrieve(current,&currententry,pl);
        if(LE(pe -> key,currententry.key))
        {
            break;
        }
    }
    Insert(current,pe,pl);
}

int Binary2Search(KeyType k, List *pl)
{
    int middle, bottom = 0, top = pl -> Size - 1;
    while(bottom <= top)
    {
        middle = (top + bottom) / 2;
        if(EQ(k,pl -> entry[middle].key))
        {
            return middle;
        }
        if(LT(k,pl -> entry[middle].key))
        {
            top = middle - 1;
        }
        else
        {
            bottom = middle + 1;
        }
    }
    return -1;
}


