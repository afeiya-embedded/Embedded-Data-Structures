#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int front; // 队列的头
    int rear;  // 队列的尾
} sqqueue_t;

// 初始化队列
sqqueue_t *sqqueue_init(void)
{
    sqqueue_t *q = malloc(sizeof(sqqueue_t));
    q->front = -1;
    q->rear = -1;
    return q;
}

// 队列是否为空
int sqqueue_isempty(sqqueue_t *q)
{
    return (q->front == q->rear);
}

// 队列是否已满
// 队满条件：(rear + 1) % MAXSIZE == front
// 队空条件：front == rear
// 为了区分满队和空队   队尾+1 == 对头 ， 此时队列容量最大，队列为满

int sqqueue_isfull(sqqueue_t *q)
{
    return ((q->rear + 1) % MAXSIZE == q->front);
}

// 入队
int sqqueue_enqueue(sqqueue_t *q, int val)
{
    if (sqqueue_isfull(q))
    {
        printf("队列已满");
        return -1;
    }
    q->rear = (q->rear + 1) % MAXSIZE; // 队尾+1 取模 MAXSIZE ， 防止队尾溢出
    q->data[q->rear] = val; // 入队 操作队尾

    return 0;
}

// 出队
int sqqueue_dequeue(sqqueue_t *q, int *val)
{
    if (sqqueue_isempty(q))
    {
        printf("队列已空");
        return -1;
    }
    q->front = (q->front + 1) % MAXSIZE; // 队头+1 取模 MAXSIZE ， 防止队头溢出
    *val = q->data[q->front]; // 出队 操作队头

    return 0;
}

int main(int argc, char const *argv[])
{
    sqqueue_t *Q = sqqueue_init();
    printf("入队顺序:");
    for (int i = 0; i < 5; i++)
    {
        if (sqqueue_enqueue(Q, i + 1) == 0)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    printf("出队顺序:");
    for (int i = 0; i < 5; i++)
    {
        int val;
        if (sqqueue_dequeue(Q, &val) == 0)
        {
            printf("%d ", val);
        }
    }
    printf("\n");

    printf("入队顺序:");
    for (int i = 0; i < 6; i++)
    {
        if (sqqueue_enqueue(Q, i + 6) == 0)
        {
            printf("%d ", i + 6);
        }
    }
    printf("\n");

    printf("出队顺序:");
    for (int i = 0; i < 6; i++)
    {
        int val;
        if (sqqueue_dequeue(Q, &val) == 0)
        {
            printf("%d ", val);
        }
    }
    printf("\n");

    return 0;
}
