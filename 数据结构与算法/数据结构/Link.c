#include <stdio.h>
#include <stdlib.h>

/*
    Describe：
    Author： maGod
*/

// 链表结构体
typedef struct Link
{
    /* data */
    int value;
    struct Link *next;
} Link;

// 链表构造方法
Link *newLink(int value)
{
    Link *node = (Link *)malloc(sizeof(Link));
    node->value = value;
    node->next = NULL;
    return node;
}

// 构建一个1-5的链表
Link *initLinkList()
{
    Link *link1 = newLink(1);
    Link *link2 = newLink(2);
    Link *link3 = newLink(3);
    Link *link4 = newLink(4);
    Link *link5 = newLink(5);

    link1->next = link2;
    link2->next = link3;
    link3->next = link4;
    link4->next = link5;

    return link1;
}

/*
打印链表
*/
void printLink(Link *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

/*
插入节点
*/
void insert(Link *head, Link *p, int position)
{
    for (size_t i = 0; i <= position; i++)
    {
        if (i == position)
        {
            Link *temp = head -> next;
            p -> next = temp;
            head -> next = p;
            break;
        }
        else
        {
            head = head->next;
        }
    }
}

/*
删除节点
*/
void delete(Link *head, int position)
{
    for (size_t i = 0; i <= position; i++)
    {
        if (i == position)
        {
            Link *needDelete = head -> next;
            Link *temp = needDelete -> next;
            head -> next = temp;
            free(needDelete);
            break;
        }
        else
        {
            head = head->next;
        }
    }
}

int main()
{
    Link *head = initLinkList();
    printLink(head);
    printf("\n");

    Link *link8 = newLink(8);

    insert(head, link8, 2);
    printLink(head);
    printf("\n");

    delete(head, 2);
    printLink(head);
    printf("\n");

    system("pause");
}