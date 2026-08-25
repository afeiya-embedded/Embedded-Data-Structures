#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int naive_match(char *text, char *pattern)
{
    int m = strlen(text);    // 主串的长度
    int n = strlen(pattern); // 模式串的长度
    int i, j;
    int count = 0;

    for (i = 0; i <= m - n; i++) // m-n 表示要移动的次数
    {
        for (j = 0; j < n; j++)
        {
            if (text[i + j] != pattern[j]) // 有一次不相等就退出比较
                break;
        }
        printf("算法匹配1次\n"); // 调试语句
        if (j == n)              // j ==n 说明连续比较n次都是相等的, 这种情况下说明 匹配成功
        {
            return i;
        }
    }
    if (count == 0)
        return -1;
}

void Next(char *T, int *next)
{
    next[1] = 0;
    next[2] = 1;
    int i = 2;
    int j = 1;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    for (int i = 1; i <= strlen(T); i++)
    {
        printf("next[%d]=%d\n", i, next[i]);
    }
}

int kmp_match(char *text, char *pattern)
{
    int next[10];
    Next(pattern, next); // 根据模式串pattern,初始化next数组
    int i = 1;
    int j = 1;
    while (i <= strlen(text) && j <= strlen(pattern))
    {
        // j==0:代表模式串的第一个字符就和当前测试的字符不相等；
        // text[i-1]==pattern[j-1],如果对应位置字符相等，指向当前测试的两个指针下标i和j都向后移
        if (j == 0 || text[i - 1] == pattern[j - 1])
        {
            i++;
            j++;
        }
        else // text[i - 1] == pattern[j - 1] 不相等表示要重新调整位置,需要重新匹配
        {
            j = next[j]; // 如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
            printf("算法匹配1次\n");
        }
    }
    if (j > strlen(pattern)) // 如果条件为真，说明匹配成功
    {
        return i - (int)strlen(pattern) - 1; // 让位置从0 开始计算
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    printf("****************KMP匹配法***********************************\n");
    int index = kmp_match("ABCABCAE", "ABCAE");
    if (index < 0)
    {
        printf("没有匹配成功\n");
    }
    else
    {
        printf("找到匹配的位置(从0开始计算):%d\n", index);
    }

    printf("****************朴素匹配法***********************************\n");
    index = naive_match("ABCABCAE", "ABCAE");
    if (index < 0)
    {
        printf("没有匹配成功\n");
    }
    else
    {
        printf("找到匹配的位置(从0开始计算):%d\n", index);
    }

    return 0;
}
