#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    /* data */
    int value;
    struct ListNode *next;
} ListNode;

// 基于链表实现的队列
typedef struct LinkListQueue
{
    /* data */
    ListNode *head, *rear;
    int size;
} LinkListQueue;

// 构造函数
LinkListQueue *newLinkListQueue()
{
    LinkListQueue *queue = (LinkListQueue *)malloc(sizeof(LinkListQueue));
    queue->head = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// 析构函数
void delLinkListQueue(LinkListQueue *queue)
{
    while (queue->head != NULL)
    {
        /* code */
        ListNode *temp = queue->head;
        free(temp);
        queue->head = queue->head->next;
    }
    free(queue);
}

// 获取队列长度
int getQueueSize(LinkListQueue *queue)
{
    return queue->size;
}

// 判断队列是否为空
int isEmpty(LinkListQueue *queue)
{
    return queue != NULL && queue->size != 0;
}

// 入队
void push(LinkListQueue *queue, int num)
{

    if (NULL == queue)
    {
        queue = newLinkListQueue();
    }

    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->value = num;

    if (queue->head == NULL)
    {
        // 如果队列为空，则令头、尾节点都指向该节点
        queue->head = node;
        queue->rear = node;
    }
    else
    {
        // 如果队列不为空，则将该节点添加到尾节点后
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// 取出队首元素
int peek(LinkListQueue *queue)
{
    if (NULL == queue)
    {
        return -1;
    }
    return queue->head->value;
}

// 出队
int pop(LinkListQueue *queue)
{
    if (NULL == queue)
    {
        return -1;
    }
    int num = peek(queue);
    ListNode *tempNode = queue->head;
    queue->head = queue->head->next;
    free(tempNode);
    queue->size--;
    return num;
}

// 打印数组
void printArray(int *nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
}

/* 打印队列 */
void printLinkedListQueue(LinkListQueue *queue)
{
    int *arr = malloc(sizeof(int) * queue->size);
    // 拷贝链表中的数据到数组
    int i;
    ListNode *node;
    for (i = 0, node = queue->head; i < queue->size; i++)
    {
        arr[i] = node->value;
        node = node->next;
    }
    printArray(arr, queue->size);
    free(arr);
}

int main()
{
    printf("start: \n");

    LinkListQueue *queue = newLinkListQueue();

    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);

    printf("push element into the queue: \n");

    printLinkedListQueue(queue);

    int num = pop(queue);
    printf("pop the num: %d", num);

    printf("pop element from the queue: \n");

    printLinkedListQueue(queue);

    system("pause");
}