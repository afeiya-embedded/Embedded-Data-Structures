#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE]; // 存储顺序表的数组
    int length;        // 顺序表长度
} sqlist_t;
//  sequence list
// typedef 定义的类型 _t

sqlist_t *sqlist_init(void)
{
    sqlist_t *list = (sqlist_t *)malloc(sizeof(sqlist_t));
    // *list 是就是一个结构体变量  (*list).length ， 简写 list->length
    list->length = 0;                          // 顺序表的长度初始化为0
    memset(list->data, 0, sizeof(list->data)); // 清空数组的值
    return list;
}

// 顺序表的插入
int sqlist_insert(sqlist_t *list, int index, int val)
{
    // index < 1  , index 是从1 开始的
    // index > list->length + 1  大于顺序表的长度是 list->length
    if (index < 1 || index > list->length + 1)
    {
        return -1; // 失败 -1
    }
    //  最后一个元素开始往后移动
    //  倒数第二个元素 移动到倒数第一个元素的位置， 一直移动到index 的位置
    //  index 指向的元素也要往后移动
    //
    for (int i = list->length - 1; i >= index - 1; i--)
    {
        // 4 3 2
        list->data[i + 1] = list->data[i]; // 往后移动1个元素
    }
    list->data[index - 1] = val; // 插入元素
    list->length++;              // 顺序表的长度增加1
    return 0;
}

// 顺序表的删除
int sqlist_delete(sqlist_t *list, int index, int *pval)
{
    // index < 1  , index 是从1 开始的
    // index > list->length + 1  大于顺序表的长度是 list->length
    if (index < 1 || index > list->length + 1)
    {
        return -1; // 失败 -1
    }
    *pval = list->data[index - 1]; //  先将删除的元素赋值给pval

    // 把后面的元素往前移动
    for (int i = index - 1; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1]; // 往前移动1个元素
    }
    list->length--; // 顺序表的长度减少1
    return 0;
}

// 顺序表的修改

int sqlist_modify(sqlist_t *list, int index, int newval)
{
    // index < 1  , index 是从1 开始的
    // index > list->length + 1  大于顺序表的长度是 list->length
    if (index < 1 || index > list->length + 1)
    {
        return -1; // 失败 -1
    }
    list->data[index - 1] = newval; // 把newval 的值更新到数组内
    return 0;
}

// 顺序表的查找
int sqlist_search(sqlist_t *list, int val)
{
    for (int i = 0; i < list->length; i++)
    {
        if (val == list->data[i]) // 查找元素
        {
            return i + 1; // 找到返回元素的位置
        }
    }
    return 0; // 没有找到返回0
}

// 顺序表的显示
int sqlist_print(sqlist_t *list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char const *argv[])
{
    sqlist_t *L = sqlist_init(); //  L = list
    for (int i = 0; i < 5; i++)
    {
        sqlist_insert(L, i + 1, i + 1);
    }
    sqlist_print(L);
    sqlist_insert(L, 3, 6);
    sqlist_print(L);
    int value;
    sqlist_delete(L, 3, &value);
    printf("删除的元素是：%d\n", value);
    sqlist_print(L);
    sqlist_delete(L, 3, &value);
    printf("删除的元素是：%d\n", value);
    sqlist_print(L);
    sqlist_modify(L, 3, 40);
    sqlist_print(L);
    int pos = sqlist_search(L, 4);
    if (pos > 0) // 查找元素
    {
        printf("%d 查找的元素在第%d个位置\n", 4, pos);
    }
    else
    {
        printf("%d 查找的元素不存在\n", 4);
    }

    pos = sqlist_search(L, 40);
    if (pos > 0) // 查找元素
    {
        printf("%d 查找的元素在第%d个位置\n", 40, pos);
    }
    else
    {
        printf("%d 查找的元素不存在\n", 40);
    }

    return 0;
}
