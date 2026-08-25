#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
} linkstring_t;

linkstring_t *linkstring_init(void)
{
    linkstring_t *h = (linkstring_t *)malloc(sizeof(linkstring_t));
    h->next = NULL;
    h->data = 0;
    return h;
}

// 尾插法
int linkstring_insert(linkstring_t *H, char *str)
{
    linkstring_t *p = H;
    while (p->next != NULL) // 找到最后一个节点
    {
        p = p->next;
    }
    int len = strlen(str);
    for (int i = 0; i < len; i++) // 遍历字符串
    {
        linkstring_t *node = (linkstring_t *)malloc(sizeof(linkstring_t));
        node->data = str[i]; // 赋值
        node->next = NULL; // 新节点的next指向NULL
        p->next = node; // 旧节点的next指向新节点
        p = node; // 新节点成为旧节点
    }
    return 0;
}

// 输出链式串的字符
int linkstring_print(linkstring_t *h)
{
    linkstring_t *p = h->next;
    while (p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

// 替换操作
int linkstring_replace(linkstring_t *h, char old, char new)
{
    linkstring_t *p = h->next;
    while (p != NULL)
    {
        if (p->data == old)
        {
            p->data = new;
        }
        p = p->next;
    }
    return 0;
}

// 删除操作
int linkstring_delete(linkstring_t *h, char c)
{
    linkstring_t *p = h;
    while (p->next != NULL)
    {
        if (p->next->data == c)
        {
            linkstring_t *q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
    return 0;
}



int main(int argc, char const *argv[])
{

    linkstring_t *H = linkstring_init();
    linkstring_insert(H, "hello,world");
    linkstring_print(H);
    linkstring_replace(H, 'l', 'L');
    linkstring_print(H);
    linkstring_delete(H, 'o');
    linkstring_print(H);




    return 0;
}
