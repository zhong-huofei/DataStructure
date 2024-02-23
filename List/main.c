#include"LinkList_Operate.h"


int main(void)
{
    LNODE* LinkList;
    LinkList = CreatingLinkList_HeadMode();
    PrintfLinkList(LinkList);
    printf("\n");
    Ruin_LinkList(LinkList);

    return 0;
}