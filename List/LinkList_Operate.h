#ifndef __LINKLIST_OPERATE_H_
#define __LINKLIST_OPERATE_H_
#include<stdio.h>
#include<stdlib.h>
//单链表结点
typedef struct Lnode
{
    int data;
    struct Lnode* next;
}LNODE;
//双链表结点
typedef struct DuLnode
{
    int data;
    struct DuLnode *next,*prior;
}DULNODE;

LNODE* CreatingLinkList_HeadMode(void);//头插法创建链表
LNODE* CreatingLinkList_TailMode(void);//尾插法创建链表
void PrintfLinkList(LNODE* LinkList);//输出链表
LNODE* GetData(LNODE* LinkList, int i);//查找第i个结点
LNODE* Locate_Lnode(LNODE* LinkList, int key);//按值查找
int Insert_Lnode(LNODE* LinkList, int i, int data);//插入结点
int Delete_Lnode(LNODE* LinkList, int i);//删除第i个结点
int Delete_LnodeData(LNODE* LinkList, int key);//按值删除
void Ruin_LinkList(LNODE* LinkList);//销毁链表
void Clear_LinkList(LNODE* LinkList);//清空链表

DULNODE* CreatingDuLinkList_HeadMode(void);
DULNODE* CreatingDuLinkList_TailMode(void);
int Insert_DuLnode(DULNODE* DuLinkList, int i, int data);
int Delete_DuLnode(DULNODE* DuLinkList, int i);

#endif

