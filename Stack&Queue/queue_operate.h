#ifndef __QUEUE_OPERATE_H_
#define __QUEUE_OPERATE_H_

#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE  1024

typedef int QueueElemType;

//链队列结点
typedef struct QNode
{
    QueueElemType data;
    struct QNode *next;
}QNode;
//链队列结构体
typedef struct LinkQueue
{
    QNode *front,*rear;
}LinkQueue;
//循环队列结构体
typedef struct LoopQueue
{
    QueueElemType *base;
    int front,rear;
}LoopQueue;

int LinkQueue_Init(LinkQueue *LQueue);//初始化链队列
int LinkQueue_Push(LinkQueue *LQueue, QueueElemType data);//链队列入队
int LinkQueue_Pop(LinkQueue *LQueue, QueueElemType *data);//链队列出队
int LoopQueue_Init(LoopQueue *LQueue);//初始化循环队列
int LoopQueue_Push(LoopQueue *LQueue, QueueElemType data);//循环队列入队
int LoopQueue_Pop(LoopQueue *LQueue, QueueElemType *data);//循环队列出队

#endif