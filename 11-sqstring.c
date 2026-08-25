#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct
{
    char data[MAXSIZE]; // 存储字符串的数组
    int length;         // 字符串的长度
} sqstring_t;           // sequeue string typedef

// 初始化字符串
sqstring_t *sqstring_init(void)
{
    sqstring_t *str = malloc(sizeof(sqstring_t));
    str->length = 0;
    memset(str->data, 0, sizeof(str->data)); // 初始化字符串为0
    return str;
}

// 字符串插入
int sqstring_insert(sqstring_t *S1, int pos, sqstring_t *S2)
{
    // memmove(dst,src, size)
    // dst : 目标地址
    // src : 源地址
    // size : 要移动的字节数
    // 把 hell     o ， 中的o 往后移动strlen(world)==5个位置
    // S1->data+pos+S2->length : 目标地址
    // S1->data+pos : 源地址
    // S1->length-pos : 要移动的字节数
    memmove(S1->data + pos + S2->length, S1->data + pos, S1->length - pos); // 效果就是：hell     o
    strncpy(S1->data + pos, S2->data, S2->length);                          // 效果就是：hellworldo
    S1->length += S2->length;
    return 0;
}

// 删除操作
int sqstring_delete(sqstring_t *S1, int pos, int len)
{
    // 把 hellworldo 中的ll ， 往后移动2个位置
    // S1->data+pos : 目标地址
    // S1->data+pos+len : 源地址
    // S1->length-pos-len+1 : 要移动的字节数， 包括\0
    memmove(S1->data + pos, S1->data + pos + len, S1->length - pos - len + 1); // 效果就是：heworldo
    return 0;
}

int sqstring_index(sqstring_t *S1, sqstring_t *S2)
{
    // 字符串的查找
    char *retp = strstr(S1->data, S2->data);
    if (retp == NULL)
    {
        return -1;
    }
    else
    {
        // retp - S1->data : 离数组第一个元素相隔元素的个数
        return retp - S1->data; // 找到的位置
    }
}

// 替换操作
int sqstring_replace(sqstring_t *S1, sqstring_t *S2, sqstring_t *S3)
{
    // S1 = "heworldo" , 把world 替换为big
    // 期望结果："hebigo"
    int ret = sqstring_index(S1, S2);
    if (ret < 0)
    {
        return -1;
    }
    // 找到字符串 ， 先删除找到的字符串
    sqstring_delete(S1, ret, S2->length);

    // 再插入替换后的字符串
    sqstring_insert(S1, ret, S3);

    return 0;
}

// 截取操作
int sqstring_substring(sqstring_t *S1, sqstring_t *S2, int pos, int len)
{
    // S1 = "hebigo" 提取出 bigo ， S2期望的结果：bigo
    strncpy(S2->data, S1->data + pos, len);
    S2->data[len] = '\0';
    S2->length = len;
    return 0;
}


int main(int argc, char const *argv[])
{
    sqstring_t *S1 = sqstring_init();
    sqstring_t *S2 = sqstring_init();
    sqstring_t *S3 = sqstring_init();
    strcpy(S1->data, "hello");
    strcpy(S2->data, "world");
    S1->length = strlen(S1->data);
    S2->length = strlen(S2->data);

    // 将 world 插入到 hello 的第4个位置， 期望的结果是： hellworldo
    sqstring_insert(S1, 4, S2);
    printf("S1 插入后:%s\n", S1->data); // S1

    // 删除操作
    // "hellworldo" 中的ll ， 期望结果："heworldo"
    sqstring_delete(S1, 2, 2);
    printf("S1 删除后:%s\n", S1->data); // S1

    // 替换操作
    // S1 = "heworldo" , 把world 替换为big
    // 期望结果："hebigo"
    strcpy(S3->data, "big");
    S3->length = strlen(S3->data);
    // S1 = heworldo
    // S2 = world    要替换的字符串
    // S3 = big      替换后的字符串
    sqstring_replace(S1, S2, S3);
    printf("S1 替换后:%s\n", S1->data); // S1

    // 截取操作 
    // S1 = "hebigo" 提取出 bigo ， S3期望的结果：bigo
    sqstring_substring(S1, S3, 2,4);
    printf("S3 截取后:%s\n", S3->data); // S3


    return 0;
}
