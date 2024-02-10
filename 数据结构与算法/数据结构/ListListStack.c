#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    /* data */
    int value;
    struct ListNode *next;
} ListNode;

//基于链表实现的栈
typedef struct
{
    ListNode *top; //头指针
    int size;      //元素个数
} LinkListStack;

//构造函数
LinkListStack *newLinkListStack()
{
    LinkListStack *s = malloc(sizeof(LinkListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

//析构
void deleteLinkListStack(LinkListStack *s)
{
    while (s->top)
    {
        ListNode *temp = s->top->next;
        free(s->top);
        s->top = temp;
    }
    free(s);
}

//获取栈元素个数
int size(LinkListStack *s)
{
    return s->size;
}

//判断栈是否为空
int isEmpty(LinkListStack *s)
{
    return 0 == s->size;
}

//入栈
void push(LinkListStack *s, int value)
{
    if (NULL == s)
    {
        s = newLinkListStack();
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->value = value; //赋值
    node->next = s->top; //在头指针前面添加节点
    s->top = node;       //重置头指针
    s->size++;
}

//访问栈顶元素
int peek(LinkListStack *s)
{
    if (isEmpty(s))
    {
        return __INT_MAX__;
    }
    return s->top->value;
}

//出栈
int pop(LinkListStack *s)
{
    int value = peek(s);
    ListNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return value;
}

int main()
{
    LinkListStack *s = newLinkListStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printf("pop 元素为: %d", pop(s));

    system("pause");
}