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
    h->data = 0; // 头节点的数据域为0
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

// 删除链表
// 正常删除1个节点， 要定位要要删除节点的前一个节点
// 如果要删除的节点是头结点 , 必须要更新一个新的头结点。
cyclist_t *cyclist_delete(cyclist_t *h, int val)
{
    cyclist_t *p = h; // p 指向头节点 , 必须定位的头节点
    cyclist_t *q;
    // 判断p->next 节点的地址 是不是和头节点重合了
    // 如果重合了， p定位到了h 的前一个节点
    while (p->next != h)
    {
        if (p->next->data == val)
        {
            q = p->next;       // 要删除的节点
            p->next = q->next; // 步骤1
            free(q);           // 步骤2
            return h;          // 返回头节点
        }
        p = p->next; // 往后移动1个节点
    }
    if (p->next == h)
    {
        if (p->next->data == val) // 要删除的节点是头节点
        {
            q = p->next;       // 要删除的节点
            p->next = q->next; // 步骤1
            free(q);           // 步骤2
            return p;          // 返回新头节点
        }
    }

    return h;
}

// 修改链表
int cyclist_modify(cyclist_t *h, int oldval, int newval)
{
    cyclist_t *p = h->next; // p 指向第一个节点
    while (p != h)          // 遍历链表
    {
        if (p->data == oldval) // 找到要修改的节点
        {
            p->data = newval;
            return 0; // 函数返回
        }
        p = p->next; // 移动节点
    }
    return 0; // 没有找到要修改的节点
}

//  查找链表
int cyclist_search(cyclist_t *h, int val)
{
    cyclist_t *p = h->next; // p 指向第一个节点
    while (p != h)          // 遍历链表
    {
        if (p->data == val) // 找到要查找的节点
        {
            return 1; // 查找成功
        }
        p = p->next; // 移动节点
    }
    return 0; // 查找失败
}



int main(int argc, char const *argv[])
{
    cyclist_t *L = cyclist_init();
    for (int i = 1; i < 11; i++)
    {
        cyclist_insert(L, i);
    }
    cyclist_print(L);
    L = cyclist_delete(L, 10);
    L = cyclist_delete(L, 0);
    L = cyclist_delete(L, 5);
    cyclist_print(L);
    cyclist_modify(L, 9, 99);
    cyclist_modify(L, 4, 44);
    cyclist_modify(L, 2, 22);
    cyclist_print(L);
    if(cyclist_search(L, 99))
    {
        printf("99 found\n");
    }
    else
    {
        printf("99 not found\n");
    }
    if(cyclist_search(L, 10))
    {
        printf("10 found\n");
    }
    else
    {
        printf("10 not found\n");
    }
    return 0;
}
