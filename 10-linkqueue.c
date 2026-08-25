#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;          // 数据域
    struct node *next; // 指针域
} linklist_t;          // 链表类型

typedef struct
{
    linklist_t *front; // 队头
    linklist_t *rear;  // 队尾
} linkqueue_t;

// 链表的初始化
linkqueue_t *linkqueue_init(void)
{
    linkqueue_t *q = (linkqueue_t *)malloc(sizeof(linkqueue_t));
    linklist_t *h = (linklist_t *)malloc(sizeof(linklist_t));
    h->next = NULL;
    q->front = h;
    q->rear = h;
    return q;
}

// 链式队列不会为满
// 链式队列会为空
// 队列是否为空
int linkqueue_isempty(linkqueue_t *q)
{
    return (q->front == q->rear);
}

// 入队  尾插法
// h 1 2 3 4 5 null
//           r p
int linkqueue_enqueue(linkqueue_t *q, int val)
{
    linklist_t *p = (linklist_t *)malloc(sizeof(linklist_t));
    p->data = val; // 给节点赋值

    p->next = q->rear->next; // 尾部插入第1步
    q->rear->next = p;       // 尾部插入第2步
    // 把rear 移动到 p的位置上
    q->rear = p;

    return 0;
}

// 出队  头删法
// h 1 2 3 4 5 null
// f p     r
int linkqueue_dequeue(linkqueue_t *q, int *val)
{
    linklist_t *p; // p 保存要删除的节点

    if (linkqueue_isempty(q))
    {
        printf("队列为空");
        return -1;
    }
    p = q->front->next; // p 指向头节点的下一个节点
    q->front->next = p->next; // 头部删除
    if(q->front->next == NULL) // 处理特出情况 队列已经空 
    {
        q->rear = q->front ; // 队尾也指向头节点
    }
    *val = p->data; // 先将数据赋值给val
    free(p);                  // 释放内存
    return 0;
}

int main(int argc, char const *argv[])
{
    linkqueue_t *Q = linkqueue_init();
    printf("入队顺序:");
    for (int i = 0; i < 5; i++)
    {
        if (linkqueue_enqueue(Q, i + 1) == 0)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    printf("出队顺序:");
    for (int i = 0; i < 5; i++)
    {
        int val;
        if (linkqueue_dequeue(Q, &val) == 0)
        {
            printf("%d ", val);
        }
    }
    printf("\n");

    printf("入队顺序:");
    for (int i = 0; i < 6; i++)
    {
        if (linkqueue_enqueue(Q, i + 6) == 0)
        {
            printf("%d ", i + 6);
        }
    }
    printf("\n");

    printf("出队顺序:");
    for (int i = 0; i < 7; i++)
    {
        int val;
        if (linkqueue_dequeue(Q, &val) == 0)
        {
            printf("%d ", val);
        }
    }
    printf("\n");
    return 0;
}
