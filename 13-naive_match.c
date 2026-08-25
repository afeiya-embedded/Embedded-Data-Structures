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

int main(int argc, char const *argv[])
{
    int index = naive_match("goodgoogle", "google");
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
