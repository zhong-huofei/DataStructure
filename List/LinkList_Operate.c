#include"LinkList_Operate.h"

//头插法创建链表
LNODE* CreatingLinkList_HeadMode(void)
{
    int data;
    LNODE *head,*p;
    head = (LNODE*)malloc(sizeof(LNODE));
    head -> next = NULL;

    while(1)
    {
        printf("Please input data(data is 3251 creating complete):\n");
        scanf("%d",&data);
        if(data == 3251) break;

        p = (LNODE*)malloc(sizeof(LNODE));
        p -> data = data;
        p ->next = head -> next;
        head -> next = p;
    }
    printf("LinkList creating complete\n");
    return head;
}
//尾插法创建链表
LNODE* CreatingLinkList_TailMode(void)
{
    int data;
    LNODE *head,*p,*tail;
    head = tail = (LNODE*)malloc(sizeof(LNODE));
    head ->next = NULL;

    while(1)
    {
        printf("Please input data(data is 3251 creating complete):\n");
        scanf("%d",&data);
        if(data == 3251) break;

        p = (LNODE*)malloc(sizeof(LNODE));
        p ->data = data;
        p ->next = tail->next;
        tail ->next = p;
        tail = p;
    }
    printf("LinkList creating complete\n");
    return head;
}
//输出链表
void PrintfLinkList(LNODE* LinkList)
{
    LNODE * index = LinkList;
    index = index -> next;
    while(index != NULL)
    {
        printf("%d\n",index->data);
        index = index ->next;
    }
}
//查找第i个节点
LNODE* GetData(LNODE* LinkList, int i)
{
    int j = 1;
    LNODE* p = LinkList ->next;

    while (p!=NULL && j<i)
    {
        p = p->next;j++;
    }
    if(p == NULL || j>i)
    {
        printf("Node does not exist!\n");
        return NULL;
    }
    else return p;
}
//按值查找
LNODE* Locate_Lnode(LNODE* LinkList, int key)
{
    LNODE* p = LinkList ->next;

    while (p != NULL)
    {
        if(p ->data == key) return p;
        else p = p ->next;
    }
    printf("Node does not exist!\n");
    return NULL;
}
//插入节点
int Insert_Lnode(LNODE* LinkList, int i, int data)
{
    int j = 0;
    LNODE *p,*q;
    p = LinkList;

    while(p != NULL && j < i - 1)
    {
        p = p->next;j++;
    }

    if(p == NULL || j>i-1) return -1;
    else
    {
        q = (LNODE*)malloc(sizeof(LNODE));
        q ->data=data;
        q ->next = p ->next;
        p ->next = q;
        return 1;
    }
}
//删除第i个节点
int Delete_Lnode(LNODE* LinkList, int i)
{
    int j = 0;
    LNODE *p,*q;
    p = LinkList;

    while(p ->next!= NULL && j < i - 1)
    {
        p = p ->next;j++;
    }

    if(p ->next == NULL || j > i - 1) return -1;
    else
    {
        q = p ->next;
        p ->next = q ->next;
        free(q);
        return 1;
    }

}
//按值删除
int Delete_LnodeData(LNODE* LinkList, int key)
{
    LNODE *p,*q;
    q = LinkList;
    p = q ->next;

    while (p != NULL && p ->data != key)
    {
        q = q ->next;
        p = p ->next;
    }

    if(p ->data == key)
    {
        q ->next = p ->next;
        free(p);
        return 1;
    }
    else return -1;
}
//销毁链表
void Ruin_LinkList(LNODE* LinkList)
{
    LNODE *p;

    while (LinkList)
    {
        p = LinkList;
        LinkList = LinkList ->next;
        free(p);
    }
    printf("Ruin LinkList\n");
}

//清空链表
void Clear_LinkList(LNODE* LinkList)
{
    LNODE *p,*q;
    p = LinkList ->next;
    while (p)
    {
        q = p ->next;
        free(p);
        p = q;
    }
    LinkList ->next = NULL;
    printf("clear LinkList\n");
}

//创建双向链表
DULNODE* CreatingDuLinkList_HeadMode(void)
{
    int data;
    DULNODE* head,*p;
    head = (DULNODE*)malloc(sizeof(DULNODE));
    head ->next = head ->prior = NULL;
    while(1)
    {
        printf("Please input data(data is 3251 creating complete):\n");
        scanf("%d",&data);
        if(data == 3251) break;

        p = (DULNODE*)malloc(sizeof(DULNODE));
        p ->data = data;
        p ->next = head ->next;
        head ->next = p;
        p ->prior = head;
    }
    printf("DuLinkList creating complete\n");
    return head;
}
//创建双向链表
DULNODE* CreatingDuLinkList_TailMode(void)
{
    int data;
    DULNODE* head,*p,*tail;
    head = tail = (DULNODE*)malloc(sizeof(DULNODE));
    head ->next = head ->prior = NULL;
    while(1)
    {
        printf("Please input data(data is 3251 creating complete):\n");
        scanf("%d",&data);
        if(data == 3251) break;

        p = (DULNODE*)malloc(sizeof(DULNODE));
        p ->data = data;
        p ->next = tail ->next;
        tail ->next = p;
        p ->prior = tail;
        tail = p;
    }
    printf("DuLinkList creating complete\n");
    return head;
}
//插入节点
int Insert_DuLnode(DULNODE* DuLinkList, int i, int data)
{
    int j;
    DULNODE *p,*q;
    p = DuLinkList;

    while(p != NULL && j < i -1)
    {
        p = p ->next;j++;
    }

    if(p == NULL || j > i - 1) return -1;
    else
    {
        q = (DULNODE*)malloc(sizeof(DULNODE));
        q ->data = data;
        q ->next = p ->next;
        q ->prior = p;
        p ->next->prior = q;
        p ->next = q;

        return 1;
    }
}
//删除结点
int Delete_DuLnode(DULNODE* DuLinkList, int i)
{
    int j;
    DULNODE *p = DuLinkList;

    while(p != NULL && j < i)
    {
        p = p ->next;j++;
    }

    if(p == NULL || j > i) return -1;
    else
    {
        p ->prior->next = p ->next;
        p ->next->prior = p ->prior;
        free(p);
        return 1;
    }
}