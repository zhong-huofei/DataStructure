#include "stack_operate.h"
//初始化栈
int SeqStack_Iint(SeqStack *S)
{
    S->base = (StackElemType*)malloc(STACK_INIT_SIZE*sizeof(StackElemType));
    if(!S->base) exit(1);
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return 0;
}
//入栈
int SeqStack_Push(SeqStack *S, StackElemType data)
{
    if(S->top - S->base >= STACK_INIT_SIZE)
    {
        S->base = (StackElemType*)realloc(S->base, (S->stackSize + STACKINCREMENT)*sizeof(StackElemType));
        if(!S->base) exit(1);
        S->top = S->base + S->stackSize;
        S->stackSize += STACKINCREMENT;
    }
    *S->top++ = data;
    return 0;
}
//出栈
int SeqStack_Pop(SeqStack *S, StackElemType *data)
{
    if(S->base == S->top) exit(1);
    else
    {
        *(data) = *--S->top;
        return 0;
    }
}
//获取栈顶元素
int SeqStack_GetTop(SeqStack *S, StackElemType *data)
{
    if(S->base == S->top) exit(1);
    else
    {
        *(data) = *(S->top - 1);
        return 0;
    }
}
//链栈入栈
LStack* LStack_Push(LStack *top, StackElemType data)
{
    LStack *p;
    p = (LStack*)malloc(sizeof(LStack));
    if(!p) return NULL;
    p->data = data;
    p->next = top;
    return p;
}
//链栈出栈
LStack* LStack_Pop(LStack *top, StackElemType *data)
{
    LStack *p;
    if(!top) return NULL;
    *data = top->data;
    p = top;
    top = p->next;
    free(p);
    return top;
}
//销毁链栈
LStack* LStack_Destroy(LStack *top)
{
    LStack *p;
    while(top)
    {
        p = top;
        top = p->next;
        free(p);
    }
    return NULL;
}