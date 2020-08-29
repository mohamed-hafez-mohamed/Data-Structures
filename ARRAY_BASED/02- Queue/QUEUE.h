#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAXQUEUE  5
typedef int       QueueEntry;

typedef struct Queue
{
    int Front;
    int Rear;
    int Size;
    QueueEntry entry[MAXQUEUE];
}Queue;

void InitializeQueue(Queue *pq);
int Append(QueueEntry *pe,Queue *pq);
void Serve(QueueEntry *pe,Queue *pq);
int  QueueEmpty(Queue *pq);
int  QueueFull(Queue *pq);
int  QueueSize(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue *pq, void (*PF)(QueueEntry e));


#endif // QUEUE_H_INCLUDED
