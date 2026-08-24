#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 32

typedef struct
{
    int data[STACK_MAX_SIZE]; // 栈的数组
    int top;                  // 栈顶指针
} sqstack_t;

// 栈的创建
sqstack_t *sqstack_init(void)
{
    sqstack_t *s = malloc(sizeof(sqstack_t));
    s->top = -1;
    return s;
}

// 判断栈是否为满
int sqstack_isfull(sqstack_t *s)
{
    if (s->top == STACK_MAX_SIZE - 1) // 栈满
    {
        return 1;
    }
    return 0;
}

// 判断栈是否为空
int sqstack_isempty(sqstack_t *s)
{
    if (s->top == -1) // 栈空
    {
        return 1;
    }
    return 0;
}

// 栈的入栈
int sqstack_push(sqstack_t *s, int val)
{
    if (sqstack_isfull(s))
    {
        printf("栈已满");
        return -1;
    }
    s->top++;
    s->data[s->top] = val;
    return 0;
}

// 栈的出栈
int sqstack_pop(sqstack_t *s, int *val)
{
    if (sqstack_isempty(s))
    {
        printf("栈为空");
        return -1;
    }
    *val = s->data[s->top];
    s->top--;
    return 0;
}

int main(int argc, char const *argv[])
{

    sqstack_t *S = sqstack_init();
    printf("入栈顺序:");
    for (int i = 0; i < STACK_MAX_SIZE + 1; i++)
    {
        if (sqstack_push(S, i + 1) >= 0)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    printf("出栈顺序:");
    for (int i = 0, val; i < STACK_MAX_SIZE + 1; i++)
    {
        if (sqstack_pop(S, &val) >= 0)
        {
            printf("%d ", val);
        }
    }
    printf("\n");

    return 0;
}
