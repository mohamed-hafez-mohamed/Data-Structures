#include "QUEUE.h"

void InitializeQueue(Queue *pq)
{
    pq -> Front = 0;
    pq -> Rear  = -1;
    pq -> Size  = 0;
}

int Append(QueueEntry *pe,Queue *pq)
{
    pq -> Rear = (pq -> Rear + 1) % (MAXQUEUE);
    pq -> entry[pq -> Rear] = *pe;
    pq -> Size++;
}

void Serve(QueueEntry *pe,Queue *pq)
{
    *pe = pq -> entry[pq -> Front];
    pq -> Front = (pq -> Front + 1) % (MAXQUEUE);
    pq -> Size--;
}

int  QueueEmpty(Queue *pq)
{
    return !pq -> Size;
}

int  QueueFull(Queue *pq)
{
    return (pq -> Size == MAXQUEUE);
}

int  QueueSize(Queue *pq)
{
    return pq -> Size;
}

void ClearQueue(Queue *pq)
{
    pq -> Front = 0;
    pq -> Rear  = -1;
    pq -> Size  = 0;
}

void TraverseQueue(Queue *pq, void (*PF)(QueueEntry e))
{
    int pos ,s = 0;
    for(pos = pq -> Front;s = pq -> Size;s++)
    {
        (*PF)(pq -> entry[pos]);
        pos = (pos+1) % (MAXQUEUE);

    }
}

