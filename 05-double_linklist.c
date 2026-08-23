#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;          // 数据域
    struct node *prev; // 指针域
    struct node *next; // 指针域
} linklist_t;          // double linklist

// 初始化双链表
linklist_t *linklist_init(void)
{
    linklist_t *h = (linklist_t *)malloc(sizeof(linklist_t));
    h->prev = NULL;
    h->next = NULL;
    h->data = 0; // 头节点的数据域为0
    return h;
}

// 双链表的插入
int linklist_insert(linklist_t *h, int val)
{
    linklist_t *p = (linklist_t *)malloc(sizeof(linklist_t));
    p->data = val;     // 赋值
    p->next = h->next; // 接链表步骤1
    h->next = p;       // 接链表步骤2
    if (p->next != NULL)
        p->next->prev = p; // 接链表步骤3
    p->prev = h;           // 接链表步骤4
    return 0;
}

// 双链表的删除
int linklist_delete(linklist_t *h, int val)
{
    linklist_t *p = h->next; // p 指向第一个节点
    while (p != NULL)
    {
        if (p->data == val)
        {
            if (p->prev != NULL)
                p->prev->next = p->next; // 前一个节点的next指向后一个节点
            if (p->next != NULL)
                p->next->prev = p->prev; // 后一个节点的prev指向前一个节点
            free(p);
            return 0;
        }

        p = p->next; // 移动节点
    }
    return 0;
}

// 显示双链表的内容
int linklist_print(linklist_t *h)
{
    linklist_t *p = h->next; // p 指向第一个节点
    printf("链表的内容:");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next; // 移动节点
    }
    printf("\n");
    return 0;
}

// 双链表的修改
int linklist_modify(linklist_t *h, int oldval, int newval)
{
    linklist_t *p = h->next; // p 指向第一个节点
    while (p != NULL)
    {
        if (p->data == oldval)
        {
            p->data = newval;
            return 0;
        }
        p = p->next; // 移动节点
    }
    return 0;
}

// 双链表的查找
int linklist_search(linklist_t *h, int val)
{
    linklist_t *p = h->next; // p 指向第一个节点
    while (p != NULL)
    {
        if (p->data == val)
        {
            return 1;
        }
        p = p->next; // 移动节点
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    linklist_t *H = linklist_init();
    for (int i = 1; i < 11; i++)
    {
        linklist_insert(H, i);
    }
    linklist_print(H);
    linklist_delete(H, 10);
    linklist_delete(H, 1);
    linklist_delete(H, 5);
    linklist_print(H);
    linklist_modify(H, 9, 99);
    linklist_modify(H, 6, 66);
    linklist_modify(H, 2, 22);
    linklist_print(H);
    if (linklist_search(H, 99))
    {
        printf("99 found\n");
    }
    else
    {
        printf("99 not found\n");
    }

    if (linklist_search(H, 1))
    {
        printf("1 found\n");
    }
    else
    {
        printf("1 not found\n");
    }

    return 0;
}
