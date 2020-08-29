
#include <stdlib.h>
#include "LIST.h"

void InitializeList(List *pl)
{
    pl -> current = NULL;
    pl -> Size  = 0;
    pl -> currentPos = 0;
}

int  Insert(int pos,ListEntry *pe,List *pl)
{
    ListNode *pn;
    pn = (ListNode*)malloc(sizeof(ListNode));
    if(! pn)
    {
      return 0;
    }
    else
    {
        pn -> entry = *pe;
        if(pos == 0)
        {
            pl -> current    = pn;
            pl -> currentPos = 0;
            pl -> current -> next     = pn;
            pl -> current -> previous = pl -> current -> next;
        }
        else
        {
            if(pl -> currentPos <= pos)
            {
               for(;pl -> currentPos != pos + 1;pl -> currentPos--)
               {
                pl -> current = pl -> current -> previous;
               }
               pn -> next = pl -> current;
               pn -> previous = pl -> current -> previous -> previous;
               pl -> current -> previous -> previous -> next = pn;
               pl -> current  -> previous = pn;
               pl -> current = pn;
            }
            else
            {
                for(;pl -> currentPos != pos - 1;pl -> currentPos++)
            {
                pl -> current = pl -> current -> next;
            }
            pn -> next = pl -> current -> next;
            pn -> previous = pl -> current;
            pl -> current -> next = pn;
            pl -> current -> previous -> previous = pn;
            pl -> current = pn;
            }
        }
        pl -> Size++;
        return 1;
    }
}

void Delete(int pos,ListEntry *pe,List *pl)
{
    ListNode *temp;
    if(pl -> currentPos == pos)
    {
        temp = pl -> current -> next;
        *pe = pl -> current -> entry;
        pl -> current -> next -> previous = pl -> current -> previous;
        pl -> current -> previous -> next = temp;
        free(pl -> current);
        pl -> current = temp;
    }
    else if(pl -> currentPos < pos)
    {
        for(;pl -> currentPos != pos + 1;pl -> currentPos--)
        {
            pl -> current = pl -> current -> previous;
        }
        temp = pl -> current -> previous -> previous;
        *pe = pl -> current -> previous -> entry;
        pl -> current -> previous -> previous -> next = pl -> current;
        pl -> current -> previous = temp;
        free(pl -> current);
        pl -> current = temp;
    }
    else
    {
        for(;pl -> currentPos != pos - 1;pl -> currentPos++)
        {
           pl -> current = pl -> current -> next;
        }
        temp = pl -> current -> next -> next;
        *pe = pl -> current -> next -> entry;
        pl -> current -> next -> next -> previous = pl -> current;
        pl -> current -> next = temp;
        free(pl -> current);
        pl -> current = temp;
    }
    pl -> Size--;
}

void  Retrieve(int pos,ListEntry *pe,List *pl)
{
    if(pl -> currentPos == pos)
    {
       *pe = pl -> current -> entry;
    }
    else if(pl -> currentPos < pos)
    {
        for(;pl -> currentPos != pos + 1;pl -> currentPos--)
        {
            pl -> current = pl -> current -> previous;
        }
        *pe = pl -> current -> previous -> entry;
    }
    else
    {
        for(;pl -> currentPos != pos - 1;pl -> currentPos++)
        {
           pl -> current = pl -> current -> next;
        }
        *pe = pl -> current -> next -> entry;
    }
}

void Replace(int pos,ListEntry *pe,List *pl)
{
    if(pl -> currentPos == pos)
    {
       pl -> current -> entry = *pe;
    }
    else if(pl -> currentPos < pos)
    {
        for(;pl -> currentPos != pos + 1;pl -> currentPos--)
        {
            pl -> current = pl -> current -> previous;
        }
        pl -> current -> previous -> entry = *pe;
    }
    else
    {
        for(;pl -> currentPos != pos - 1;pl -> currentPos++)
        {
           pl -> current = pl -> current -> next;
        }
        pl -> current -> next -> entry = *pe;
    }
}

int  ListEmpty(List *pl)
{
    return !pl -> Size;
}

int  ListFull(List *pl)
{
    return 0;
}

int  ListSize(List *pl)
{
    return pl -> Size;
}

void ClearList(List *pl)
{
    ListNode *qn;
    while(pl ->current)
    {
       qn = pl ->current -> next;
       free(pl ->current);
       pl ->current = qn;
    }
}

void TraverseList(List *pl, void (*PF)(ListEntry e))
{
    ListNode *pn;
    for(pn = pl ->current;pn;pn = pn -> next)
    {
        (*PF)(pn -> entry);
    }
}
