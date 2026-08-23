#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域
} linklist_t;          // 链表类型

// 链表的初始化
linklist_t *linklist_init(void)
{
    linklist_t *h = (linklist_t *)malloc(sizeof(linklist_t));
    h->data = 0;
    h->next = NULL;
    return h;
}

int linklist_insert(linklist_t *h, int val)
{
    linklist_t *p = (linklist_t *)malloc(sizeof(linklist_t));
    p->data = val;

    // 头插法
    p->next = h->next; // 步骤1
    h->next = p;       // 步骤2

    return 0;
}

int linklist_delete(linklist_t *h, int val)
{
    linklist_t *p = h; // p 指向头节点
    linklist_t *q;
    while (p->next != NULL)
    {
        if (p->next->data == val)
        {
            q = p->next;       // q 指向要删除的节点
            p->next = q->next; // 步骤1
            free(q);           // 步骤2
            return 0;          // 不返回时， 删除最后1个节点时会出问题
        }
        p = p->next; // 移动节点
    }

    return -1;
}

int linklist_modify(linklist_t *h, int oldval, int newval)
{
    linklist_t *p = h->next; // p 指向第一个节点
    while (p != NULL)        // 遍历链表
    {
        if (p->data == oldval) // 找到要修改的节点
        {
            p->data = newval;
            return 0; // 函数返回
        }
        p = p->next; // 移动节点
    }
    printf("\n");
    return 0;
}

// 链表的查找
int linklist_search(linklist_t *h, int val)
{
    linklist_t *p = h->next; // p 指向第一个节点
    while (p != NULL)        // 遍历链表
    {
        if (p->data == val) // 找到要查找的节点
        {
            return 1; // 查找成功
        }
        p = p->next; // 移动节点
    }

    return 0; // 查找失败
}

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
}

int linklist_reverse(linklist_t *h)
{
    linklist_t *p = h->next; // p 指向第一个节点
    linklist_t *q = NULL;
    h->next = NULL;
    while (p != NULL)
    {
        q = p->next;       // q 保存p的下一个节点
        p->next = h->next; // 步骤1
        h->next = p;       // 步骤2
        p = q;             // 步骤3 往后移动1个节点
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    linklist_t *H = linklist_init(); // H = h
    for (int i = 1; i < 11; i++)
    {
        linklist_insert(H, i); // 插入 1 2 3 4 5 6 7 8 9 10
    }
    linklist_print(H);
    linklist_delete(H, 10);
    linklist_delete(H, 1);
    linklist_delete(H, 5);
    linklist_print(H);
    linklist_modify(H, 9, 99);
    linklist_modify(H, 4, 44);
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
    if (linklist_search(H, 10))
    {
        printf("10 found\n");
    }
    else
    {
        printf("10 not found\n");
    }
    linklist_reverse(H); 
    linklist_print(H);
    linklist_reverse(H); 
    linklist_print(H);

    return 0;
}
