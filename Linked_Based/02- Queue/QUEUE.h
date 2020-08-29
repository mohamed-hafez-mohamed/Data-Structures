#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef int  QueueEntry;

typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct Queue
{
    QueueNode *Front;
    QueueNode *Rear;
    int Size;
}Queue;

void InitializeQueue(Queue *pq);
int  Append(QueueEntry *pe,Queue *pq);
void Serve(QueueEntry *pe,Queue *pq);
int  QueueEmpty(Queue *pq);
int  QueueFull(Queue *pq);
int  QueueSize(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue *pq, void (*PF)(QueueEntry e));

#endif // QUEUE_H_INCLUDED
