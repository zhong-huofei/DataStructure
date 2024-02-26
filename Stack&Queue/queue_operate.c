#include"queue_operate.h"

//初始化链队列
int LinkQueue_Init(LinkQueue *LQueue)
{
    LQueue->front = LQueue->rear = (QNode*)malloc(sizeof(QNode));
    if(!LQueue->front) return NULL;
    LQueue->front->next = NULL;
    return LQueue;
}
//链队列入队
int LinkQueue_Push(LinkQueue *LQueue, QueueElemType data)
{
    QNode *p;
    p = (QNode*)malloc(sizeof(QNode));
    if(!p) return -1;
    p->data = data;
    p->next = NULL;
    LQueue->rear->next = p;
    LQueue->rear = p;
    return 1;
}
//链队列出队
int LinkQueue_Pop(LinkQueue *LQueue, QueueElemType *data)
{
    QNode *p;
    if(LQueue->front == LQueue->rear) return -1;
    p = LQueue->front->next;
    *data = p->data;
    LQueue->front->next = p->next;
    if(LQueue->rear == p) LQueue->rear = LQueue->front;
    free(p);
    return 1;
}
//初始化循环队列
int LoopQueue_Init(LoopQueue *LQueue)
{
    LQueue->base = (QueueElemType*)malloc(sizeof(QueueElemType)*MAX_QUEUE_SIZE);
    if(!LQueue->base) return -1;
    LQueue->front = LQueue->rear = 0;
    return 1;
}
//循环队列入队
int LoopQueue_Push(LoopQueue *LQueue, QueueElemType data)
{
    if((LQueue->rear + 1)%MAX_QUEUE_SIZE == LQueue->front) return -1;
    LQueue->base[LQueue->rear] = data;
    LQueue->rear = (LQueue->rear + 1)%MAX_QUEUE_SIZE;
    return 1;
}
//循环队列出队
int LoopQueue_Pop(LoopQueue *LQueue, QueueElemType *data)
{
    if(LQueue->front == LQueue->rear) return -1;
    *data = LQueue->base[LQueue->front];
    LQueue->front = (LQueue->front + 1)%MAX_QUEUE_SIZE;
    return 1;
}