
#include <stdlib.h>
#include "LIST.h"

void InitializeList(List *pl)
{
    pl -> head = NULL;
    pl -> Size  = 0;
}

int  Insert(int pos,ListEntry *pe,List *pl)
{
    ListNode *pn;
    pn = (ListNode *)malloc(sizeof(ListNode));

    if(! pn)
    {
      return 0;
    }
    else
    {
    pn -> entry = *pe;
    pn ->next = NULL;
    if (pos == 0)
    {
        pn -> next = pl -> head;
        pl -> head = pn;
	    pl -> currentpos = 0;
        pl -> current = pl -> head;
   }
   else
   {
	if (pos <= pl -> currentpos)
	{
		pl -> currentpos = 0;
		pl -> current    = pl -> head;
	}
	    for(; pl -> currentpos != pos - 1; pl -> currentpos++)
        {
            pl -> current = pl -> current -> next;
        }
	   pn -> next = pl-> current -> next;
	   pl -> current -> next = pn;
   }
    pl -> Size++;
    return 1;
    }
}

void Delete(int pos,ListEntry *pe,List *pl)
{
   ListNode *tmp;
   if (pos == 0)
    {
	   *pe = pl -> head -> entry;
	   pl -> current = pl -> head -> next;
	   free(pl -> head);
	   pl -> head = pl -> current;
	   pl -> currentpos = 0;
   }
   else
   {
 	if (pos <= pl -> currentpos)
 	{
		pl -> currentpos = 0;
		pl -> current = pl -> head;
	}
	for(; pl -> currentpos != pos - 1; pl -> currentpos++)
    {
        pl -> current = pl-> current -> next;
    }
	*pe = pl-> current -> next -> entry;
	tmp = pl -> current -> next -> next;
	free(pl -> current -> next);
	pl -> current -> next = tmp;
   }
	pl -> Size--;

}

void  Retrieve(int pos,ListEntry *pe,List *pl)
{
    if (pos == 0)
    {
	   *pe = pl -> head -> entry;
    }
    if (pos <= pl -> currentpos)
 	{
		pl -> currentpos = 0;
		pl -> current = pl -> head;
	}
	for(; pl -> currentpos != pos - 1; pl -> currentpos++)
    {
        pl -> current = pl-> current -> next;
    }
    *pe = pl-> current -> next -> entry;
}

void Replace(int pos,ListEntry *pe,List *pl)
{
    if (pos == 0)
    {
	   *pe = pl -> head -> entry;
    }
    if (pos <= pl -> currentpos)
 	{
		pl -> currentpos = 0;
		pl -> current = pl -> head;
	}
	for(; pl -> currentpos != pos - 1; pl -> currentpos++)
    {
        pl -> current = pl-> current -> next;
    }
    pl-> current -> next -> entry = *pe;
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
    while(pl -> head)
    {
       qn = pl -> head -> next;
       free(pl -> head);
       pl -> head = qn;
    }
}

void TraverseList(List *pl, void (*PF)(ListEntry e))
{
    ListNode *pn;
    for(pn = pl -> head;pn;pn = pn -> next)
    {
        (*PF)(pn -> entry);
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



