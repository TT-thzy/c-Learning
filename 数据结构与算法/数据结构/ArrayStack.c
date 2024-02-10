#include <stdio.h>
#include <stdlib.h>

/* 基于数组实现的栈 */
typedef struct
{
    int *data;
    int size;
} ArrayStack;

/* 构造函数 */
ArrayStack *newArrayStack()
{
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    // 初始化一个大容量，避免扩容
    stack->data = malloc(sizeof(int) * __INT_MAX__);
    stack->size = 0;
    return stack;
}

/* 析构函数 */
void delArrayStack(ArrayStack *stack)
{
    free(stack->data);
    free(stack);
}

/* 获取栈的长度 */
int size(ArrayStack *stack)
{
    return stack->size;
}

/* 判断栈是否为空 */
int isEmpty(ArrayStack *stack)
{
    return stack->size == 0;
}

/* 入栈 */
void push(ArrayStack *stack, int num)
{
    if (stack->size == __INT_MAX__)
    {
        printf("栈已满\n");
        return;
    }
    stack->data[stack->size] = num;
    stack->size++;
}

/* 访问栈顶元素 */
int peek(ArrayStack *stack)
{
    if (stack->size == 0)
    {
        printf("栈为空\n");
        return __INT_MAX__;
    }
    return stack->data[stack->size - 1];
}

/* 出栈 */
int pop(ArrayStack *stack)
{
    int val = peek(stack);
    stack->size--;
    return val;
}

int main()
{
    ArrayStack *s = newArrayStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printf("pop 元素为: %d", pop(s));

    system("pause");
}