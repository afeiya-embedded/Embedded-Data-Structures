#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域
} linklist_t;

linklist_t *linkstack_init(void)
{
    linklist_t *s = malloc(sizeof(linklist_t));
    s->data = 0;
    s->next = NULL;
    return s;
}

// 判断栈是否为空
int linkstack_isempty(linklist_t *s)
{
    if (s->next == NULL)
    {
        return 1;
    }
    return 0;
}

// 入栈  头部插入
int linkstack_push(linklist_t *s, int val)
{
    linklist_t *p = malloc(sizeof(linklist_t));
    p->data = val; // 给节点赋值

    p->next = s->next; // 步骤1
    s->next = p;       // 步骤2
    return 0;
}

// 出栈  头部删除发
int linkstack_pop(linklist_t *s, int *val)
{
    linklist_t *p = s->next; // p 指向头节点的下一个节点
    if (linkstack_isempty(s))
    {
        printf("栈为空");
        return -1;
    }
    *val = p->data;    // 先将数据赋值给val
    s->next = p->next; // 头部删除
    free(p);           // 释放内存
    return 0;
}

int main(int argc, char const *argv[])
{
    linklist_t *S = linkstack_init();
    printf("入栈顺序:");
    for (int i = 0; i < 33; i++)
    {
        linkstack_push(S, i + 1);
        printf("%d ", i + 1);
    }
    printf("\n");
    printf("出栈顺序:");
    for (int i = 0, val; i < 33 + 1; i++)
    {
        if (linkstack_pop(S, &val) >= 0)
        {
            printf("%d ", val);
        }
    }
    printf("\n");

    return 0;
}
