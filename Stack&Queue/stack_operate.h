#ifndef __STACK_OPERATE_H_
#define __STACK_OPERATE_H_

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define STACK_INIT_SIZE     100
#define STACKINCREMENT      10

typedef char StackElemType;
//链栈结点
typedef struct node
{
    StackElemType data;
    struct node *next;
}LStack;
//链栈结构体
typedef struct LinkStack
{
    LStack *top;
    int stackSize;
}LinkStack;
//顺序栈结构体
typedef struct SeqStack
{
    StackElemType* base;
    StackElemType* top;
    int stackSize;
}SeqStack;

int SeqStack_Iint(SeqStack *S);//初始化栈
int SeqStack_Push(SeqStack *S, StackElemType data);//入栈
int SeqStack_Pop(SeqStack *S, StackElemType *data);//出栈
int SeqStack_GetTop(SeqStack *S, StackElemType *data);//获取栈顶元素
LStack* LStack_Push(LStack *top, StackElemType data);//链栈入栈
LStack* LStack_Pop(LStack *top, StackElemType *data);//链栈出栈
LStack* LStack_Destroy(LStack *top);//销毁链栈

#endif

