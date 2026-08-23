#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域
} cyclist_t;           // crcle list

cyclist_t *cyclist_init(void)
{
    cyclist_t *h = malloc(sizeof(cyclist_t));
    h->data = 8; // 头节点的数据域为0
    h->next = h; // 头节点的指针域指向自己
    return h;
}

int cyclist_insert(cyclist_t *h, int val)
{
    cyclist_t *p = malloc(sizeof(cyclist_t));
    p->data = val;     // 赋值
    p->next = h->next; // 接链表步骤1
    h->next = p;       // 接链表步骤2
    return 0;
}

// 遍历链表
int cyclist_print(cyclist_t *h)
{
    cyclist_t *p = h->next; // p 指向第一个节点
    printf("链表的内容:");
    // p != h
    // p == h   链表已经循环一遍
    while (p != h)
    {
        printf("%d ", p->data);
        p = p->next; // 移动节点
    }
    if (p == h) // 表示链表循环正好一周
    {
        printf("%d ", p->data);
    }

    printf("\n");
}

// 约瑟夫问题
int joseph(int n, int k, int m)
{
    cyclist_t *L = cyclist_init();
    cyclist_t *q = NULL; // 保存要删除的节点

    for (int i = n - 1; i > 0; i--)
    {
        cyclist_insert(L, i);
    }
    cyclist_print(L);
    // 从第k个节点开始数
    cyclist_t *p = L->next; // 指向1节点
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next; // 指向3节点
    }
    printf("出列顺序为:");

    while (p->next != p) // p->next == p  , 只剩下1个节点了
    {
        // 从3节点开始数，数到4节点
        for (int i = 0; i < m - 2; i++)
        {
            p = p->next; // 移动M-2 次
        }
        // 删除节点
        q = p->next;       // 要删除的节点
        p->next = q->next; // 步骤1
        printf("%d ", q->data);
        free(q);     // 步骤2
        p = p->next; // 更新p的位置
    }
    printf("%d\n", p->data);
    free(p); // 释放头节点

    return 0;
}

int main(int argc, char const *argv[])
{
    joseph(8, 3, 4);
    return 0;
}
