#include "stack_operate.h"
//进制转换
void DecimalConversion(int N, int binary)
{
    LStack *top = NULL;
    StackElemType data;
    while (N)
    {
        top = LStack_Push(top, N % binary);
        N /= binary;
    }

    while(top)
    {
        top = LStack_Pop(top, &data);
        printf("%d",data);
    }
    printf("\n");
}
//括号检测
int ParenthesisDetection(char *arr, int num)
{
    LStack *top = NULL;
    StackElemType data;

    for(int i = 0; i < num; i++)
    {
        if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            top = LStack_Push(top, (StackElemType)arr[i]);
        }
        else if(arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            top = LStack_Pop(top, &data);
            if(!((data == '(' && arr[i] == ')') || (data == '[' && arr[i] == ']') || (data == '{' && arr[i] == '}')))
            {
                return -1;
            }
        }
    }

    if(top) return -1;
    return 1;
}
int main(void)
{
    int N = 0;
    char arr[100] = {0};
    printf("Please input string:\n");
    scanf("%s",arr);
    if(-1 == ParenthesisDetection(arr, 100))
    {
        printf("Parenthesis is erro!!!\n");
    }
    else
    {
        printf("Parenthesis is normal\n");
    }
    return 0;
}
